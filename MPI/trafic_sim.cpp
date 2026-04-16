#include <mpi.h>
#include <iostream>
#include <vector>
#include <random>

std::vector<int> makeRandomBinaryArray(int size) {
    std::vector<int> arr(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }

    return arr;
}
void visulise(const std::vector<int>& arr){
    for(const int& curr : arr){
        if(curr == 0){
            std::cout<<' ';
        }else{
            std::cout<<'#';
        }
    }
    std::cout<<'\n';
}

constexpr uint8_t ARR_SIZE = 100;
constexpr uint8_t ITERATIONS_COUNT = 100;
int main(int argC, char** argV){

    MPI_Init(&argC, &argV);
 
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
 
    
    if(rank == 0){
        std::vector<int> arr = makeRandomBinaryArray(ARR_SIZE);

        int commonSize = ARR_SIZE /  (size - 1);
        int rem = ARR_SIZE  % (size - 1);
        for(int i = 1; i < size; i++){
            if(i == size - 1){
                MPI_Send(&arr[(i-1) * commonSize] , commonSize + rem, MPI_INT , i , 0 , MPI_COMM_WORLD);
            }else{
                MPI_Send(&arr[(i-1) * commonSize] , commonSize , MPI_INT , i , 0 , MPI_COMM_WORLD);
            }
        }
        visulise(arr);

        for(int iter=0; iter<ITERATIONS_COUNT; iter++){
            for(int j = 1 ; j < size; j++){
                int count = commonSize;
                count += (j == size - 1 ? rem : 0);

                MPI_Recv(&arr[(j-1)*commonSize], count, MPI_INT, j, iter, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
            visulise(arr);
        }


    }else{
        MPI_Status status;
        int count;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);

        std::vector<int> vec(count);
        MPI_Recv(vec.data(), count, MPI_INT,
            0, 0, MPI_COMM_WORLD,
            MPI_STATUS_IGNORE);

        int left = rank - 1 == 0 ? size - 1 : rank - 1;
        int rigth = rank + 1 == size ? 1 : rank + 1;

        for(int iter=0; iter<ITERATIONS_COUNT; iter++){
            MPI_Send( &vec[0]            , 1 , MPI_INT , left  , 0 , MPI_COMM_WORLD);
            MPI_Send( &vec[vec.size()-1] , 1 , MPI_INT , rigth , 0 , MPI_COMM_WORLD);

            int prevCell, nextCell;
            MPI_Recv(&prevCell , 1 , MPI_INT , left  , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE);
            MPI_Recv(&nextCell , 1 , MPI_INT , rigth , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE);

            std::vector<int> tempVec(count);
            for(int j = 0; j<vec.size(); j++){
                int pr, nx; //this will bug with array size of 1
                if(j == 0){ 
                    pr = prevCell;
                    nx = vec[j+1];
                }else if(j == vec.size() - 1){
                    pr = vec[j - 1];
                    nx = nextCell;
                }else{  
                    pr = vec[j - 1];
                    nx = vec[j + 1];
                }

                if( vec[j] == 0){ //logic simpifies to this
                    tempVec[j] = pr;
                }else{
                    tempVec[j] = nx;
                }


            } 
            vec = tempVec;
            MPI_Send( &vec[0] , count , MPI_INT , 0 , iter, MPI_COMM_WORLD);         
        }

        //std::cout<<rank<<" "<<vec.size()<<"\n";
        //std::cout<<rank<<' '<<left<<' '<<rigth<<'\n';
    }

    MPI_Finalize();
}
