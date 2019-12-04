
#include <stdio.h>
#include <utilitiy.h>
#include <algorithm.h>


struct pair_int_int {
    int first;
    int second;
};

struct pair_path_bool {

    Path first;
    bool second;

};


pair_int_int make_pair(conts int & a, const int & b){

  struct pair_int_int apair;

  apair.first = a;
  apair.second = b;

  return apair;

}


pair_path_bool make_pair_path(conts path & a, const bool & b){

  struct pair_path_bool apair;

  apair.first = a;
  apair.second = b;

  return apair;

}

pair_int_int operator+(const pair_int_int & a, const pair_int_int & b){

  return make_pair(a.first + b.first, a.second + b.second);

}


//template class that has not been figured out yet
//TODO when needed

//generate all positions needed

pair_int_int * moves(const pair_int_int pos){

  pair_int_int mvs[8];

  mvs[0] = make_pair( pos.first + 1 , pos.second + 2 );
  mvs[1] = make_pair( pos.first + 2, pos.second + 1 );
  mvs[2] = make_pair( pos.first + 2 , pos.second - 1);
  mvs[3] = make_pair( pos.first + 1 ,  pos.second - 2);
  mvs[4] = make_pair( pos.first - 1,  pos.second - 2 );
  mvs[5] = make_pair( pos.first - 2,  pos.second - 1);
  mvs[6] = make_pair( pos.first - 2 ,  pos.second + 1 );
  mvs[7] = make_pair( pos.first - 1  ,  pos.second + 2) };
  return mvs;

}

//get legal moves

pair_int_int * legal_moves (int size, Path path, pair_int_int pos){

  pair_int_int mvs[8] = moves(pos);

  pair_int_int temp[8];

  pair_int_int middleman[8];


  int size = 8;
  int count = 0;
  for (i = 0; i < size; i++){

      if ( (mvs[i].first >= 0) && (mvs[i].first < size) && (mvs[i].second >= 0) && (mvs[i].second < size) ){

        middleman[i] = mvs[i]
        count++;

      }
      else{
        middleman[i] = NULL
      }

  }

  pair_int_int final[count];

  j = 0;

  for (int i = 0; i < size; i++){

    if middleman[i] != NULL){

      final[j] = middleman[i];
      j++;

    }

  }


  return final;

}




pair_path_bool singlemove(int size, Path path){
  if(path.size == size * size){
        return make_pair_path(path, true);
  }
  else{
    pair_int_int moves * = legal_moves(size, path, path.at(path.size()-1  )  ) ;
    if(moves.size == 0){
      pair_int_int emptyp * = {};
      return make_pair_bool(emptyp, false);
    }
    else{
      Path emptyp = {};
      pair_path_bool *  newPaths = {};


      pair_path_bool newPath = transform_reduce(moves, make_pair_path(emptyp, false), [path, size ]( pair_path_bool check, const pair_int_int pos){
          pair<Path, bool> fina;

          if(check.second){
            path emptyp = {};
            fina = make_pair_path(emptyp, false);
          }
          else{
          Path list = {  pos };
          Path finalp = {};

            for(int i = 0; i < finalp.size; i++){

              finalp[i] = path[i]
            }


              fina = singlemove(size, finalp);


          }
          if(fina.second){
            return fina;
          }
          else{
            return check;
          }

      },[ ](const pair_int_int pos){

          return pos;



      });


      return newPath;
    }

  }
}






pair_path_bool first_tour (int size, Path path){

  pair_path_bool a = singlemove(size, path);

  return a;

}



int main(){
  for (int dim = 1; dim <= 8; ++dim) {
      printf("Looking for tour on a ");
      printf(dim);
      printf(" x ");
      printf(dim);
      printf(" board\n");

      pair_path_bool tour = first_tour(dim, Path{{0,0}});

      if (!tour.second) {
          printf("No tour found\n");
      } else {
          tour.first.print
          }
      }

    return 0;

}
