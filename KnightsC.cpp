#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <cstdint>

using std::make_pair;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::get;

typedef vector<pair<int,int> > Path;

//helper function
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

//template function

template<class InputIt, class T, class Red, class Trans>
T transform_reduce(InputIt itr, InputIt last, T init, Red red, Trans trans) {
	while (itr != last) {
		init = red(init, trans(*itr));
		++itr;
	}
	return init;
}


//generate all positions clockwise 
//move function

	vector<pair<int, int>> moves (pair<int, int> pos){

	

		vector<pair<int, int>> mvs = { make_pair( get<0>(pos) + 1 , get<1>(pos) + 2 ), make_pair( get<0>(pos) + 2, get<1>(pos) + 1 ), make_pair( get<0>(pos) + 2 , get<1>(pos) - 1),  make_pair( get<0>(pos) + 1 , get<1>(pos) - 2),  make_pair( get<0>(pos) - 1, get<1>(pos) - 2 ),  make_pair( get<0>(pos) - 2, get<1>(pos) - 1),  make_pair( get<0>(pos) - 2 , get<1>(pos) + 1 ),  make_pair( get<0>(pos) - 1  , get<1>(pos) + 2) };
		vector<pair<int, int>> useless;
		return mvs;		

	}	 


	vector<pair<int, int>> legal_moves (int size, Path path, pair<int, int> pos){

		vector<pair<int, int>> mvs = moves(pos);
		
		vector<pair<int, int>> lglmvs = {};

		vector<pair<int, int>> middleman = {};

		copy_if(mvs.begin(), mvs.end(),std::back_inserter(middleman),[size](const pair<int, int> pos) {		
		
			return ( (get<0>(pos) >= 0 )&& 	(get<0>(pos) < size) && (get<1>(pos) >= 0 )&& (get<1>(pos) < size) );
		
		});

		copy_if(middleman.begin(), middleman.end(),std::back_inserter(lglmvs),[path](const pair<int, int> pos) {		
		
			auto ans = find(path.begin(), path.end(), pos);
			return (ans  == path.end()  );
			
		});
		
		return lglmvs;

	}


	pair<Path, bool> singlemove(int size, Path path){
		if(path.size() == size * size){
					return make_pair(path, true);
		}
		else{
			vector<pair<int, int>> moves = legal_moves(size, path, path.at(path.size()-1  )  ) ;
			if(moves.size() == 0){

				vector<pair<int, int>> emptyp = {};
				return make_pair(emptyp, false);
			}
			else{
				Path emptyp = {};
				vector<pair<Path, bool>> newPaths = {};

				
	
				pair<Path, bool> newPath = transform_reduce(moves.begin(), moves.end(), make_pair(emptyp, false), [path, size ]( pair<Path, bool> check, const pair<int, int> pos){
						pair<Path, bool> fina;

						if(get<1>(check)){
							Path emptyp = {};
							fina = make_pair(emptyp, false);
						}
						else{
						Path list = {  pos };		
						Path finalp = {};
						copy(path.begin(), path.end(), back_inserter(finalp));
    						copy(list.begin(), list.end(), back_inserter(finalp));

						
	
    						fina = singlemove(size, finalp);
					
						
						}
						if(get<1>(fina)){
							return fina;
						}
						else{
							return check; 
						}

				},[ ](const pair<int, int> pos){
						
						return pos;
				
						

				});

				
				return newPath; 
			}
	
		}
	}

	pair<Path, bool> first_tour (int size, Path path){
		pair<Path, bool> a =  singlemove(size, path);

		return a;
		
	}


int main() {
    for (int dim = 1; dim <= 8; ++dim) {
        cout << "Looking for tour on a " << dim << " x " << dim << " board\n";
        auto tour = first_tour(dim, Path{{0,0}});
        
        if (!tour.second) {
            cout << "No tour found\n";
        } else {
            for (int row = 0; row < dim; ++row) {
                for (int col = 0; col < dim; ++col) {
                    cout << std::setw(2);
                    cout << std::distance(tour.first.begin(),
                                          std::find(tour.first.begin(), tour.first.end(), make_pair(row,col)));
                    cout << " ";
                }
                cout << endl;
            }
        }
    }
}


