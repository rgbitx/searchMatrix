#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target){

    int rowBegin = 0, rowEnd = matrix.size()-1;
    int colBegin = 0, colEnd = matrix[0].size()-1;
    int rowMid = 0, colMid = 0;

    while (rowBegin + 1 < rowEnd){
        rowMid = rowBegin + (rowEnd - rowBegin)/2;

        if (matrix[rowMid][0] == target){
            return true;
        } else if(matrix[rowMid][0] < target){
            rowBegin = rowMid;
        } else {
            rowEnd = rowMid;
        }

    }

    while(colBegin + 1 < colEnd){
        colMid = colBegin + (colEnd - colBegin)/2;

        if(matrix[rowMid][colMid] == target){
            return true;
        } else if (matrix[rowMid][colMid] < target){
            colBegin = colMid;
        } else {
            colEnd = colMid;
        }
    }

    return false;

}

int main() {
    cout << "Hello, World!" << endl;

    vector<vector<int>> matrix={
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,50}
    };

    int target=19;

    bool ret=searchMatrix(matrix, target);

    if (ret) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }

    return 0;
}