#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> ReverseMatrix(vector<vector<int>> matrix){
	/*
		Assign a matrx and reverse the order by expanding the matrix from the middle point.

		Params {
			matrix <vector<vector<int>>> : matrix of undeclared size;
		}

		Returns {
			dummy_matrix <vector<vector<int>>> : reversed matrix.
		}

	*/
	int rows = matrix.size();
    int cols = matrix[0].size();
    int M = cols / 2;

    vector<vector<int>> dummy_matrix(
        rows, vector<int>(cols, -1)
    );

    for (int k=0; k< rows; k++){
    	dummy_matrix[k][M] = matrix[k][M];

    	for (int i = 0; i < M; i++) {
	        dummy_matrix[k][i] = matrix[k][M - 1 - i];
	    	}

	    for (int i = M+1; i < cols; i++) {
	        dummy_matrix[k][i] = matrix[k][i];
	    }
	}

    return dummy_matrix;
}


int main() {

    vector<vector<int>> original_matrix = {
    	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    };

    vector<vector<int>> DummyMatrix = ReverseMatrix(original_matrix);

    int rows = DummyMatrix.size();
    int cols = DummyMatrix[0].size();

    cout << "Reordered matrix:\n";
	for (int k = 0; k < rows; k++) {
    	for (int value : DummyMatrix[k]) {
        	cout << value << " ";
    	}
    	cout << endl;
    }

    return 0;
}
