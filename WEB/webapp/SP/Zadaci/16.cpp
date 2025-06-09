Да се напише програма која вчитува квадратна матрица. На почетокот се внесува бројот на редици и колони N на матрицата, а потоа и елементите на матрицата. Да се трансформира матрицата на тој начин што секој негативен број во неа би се заменил со збирот на неговите соседи. Соседи на даден број во матрица се броевите до него (гледано хоризонтално и вертикално).



  #include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int matrix[n][n];
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (matrix[i][j] < 0){
                int sum=0;
                if(j-1>=0){
                    sum+=matrix[i][j-1];
                }if(i+1 < n){
                    sum+=matrix[i+1][j];
                }if(i-1>=0){
                    sum+=matrix[i-1][j];
                }
                if(j+1 <=n-1){
                    sum+=matrix[i][j+1];
                }
                matrix[i][j]=sum;
            }
        }
        
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
