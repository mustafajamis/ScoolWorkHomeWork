
//  Mustafa Jamshidi (T686B548)

#include <iostream>
#include <vector>
#include <numeric>

// TODO: implement this function to return a Pascal Triangle
std::vector<std::vector<int>> pascalTriangle(int row) {
    // Condition to return a empty vector if rows are exceeding 16
    if (row > 17 || row < 0){
        return std::vector<std::vector<int>>();
    }

    std::vector<std::vector<int>> pt;
    for (int i = 0; i < row; i++){
        // conditon for the first row.
        if(i == 0){
            pt.push_back(std::vector<int> {1});
        }else{
            // adding as the first integer in every row.
            std::vector<int> tmp {1};
            // logic for middle numbers
            for(int j = 0; j < i -1; j++){
                int sum = pt[i-1][j] + pt[i-1][j+1];
                tmp.push_back(sum);
            }
            // Adding one to end of each row
            tmp.push_back(1);
            pt.push_back(tmp);
        }

    }
    return pt;
}

// TODO: implement this function to print Pascal Triangles
void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    // Accessing each vector
    for (int i = 0; i < triangle.size(); i++){
        // for loop for spacing
        for (int spaces = triangle.size()-i-1; spaces > 0; spaces--){
            std::cout << " ";
        }
        // Printing the integer of the inside vector
        for(int j = 0; j < triangle[i].size(); j++){
            std::cout << triangle[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//// TODO: implement this function to return comparison result. See main() for usage.
std::vector<bool> compare(const std::vector<std::vector<int>>& triangle, const std::vector<int>& allegedSummations){
    // creating a bool vector
    std::vector<bool> viBool;
    for (int i = 0; i < triangle.size(); i++){
        // getting the sum of ingeters in each inside vector
        int sum = std::accumulate(triangle[i].begin(), triangle[i].end(), 0);
        // comparing the sum with the alleged vector
        bool check = (sum == allegedSummations[i]);
        viBool.push_back(check);
    }
    
    return viBool;
}

int main(){

    // part 1: generate and print Pascal Triangle
    int rows = 8;
    auto triangle = pascalTriangle(rows);
    printPascalTriangle(triangle);
    std::cout << std::endl;

    // part 2: check alleged summations
    // expected returrn: {1, 1, 0, 1, 0, 1, 0, 1, 1, 0}
    std::vector<int> allegedSum{1, 2, 5, 8, 17, 32, 65, 128, 256, 511};
    auto sumCheck = compare(pascalTriangle(allegedSum.size()), allegedSum);
    for (auto b : sumCheck) {
        std::cout << b << " ";
    }

    std::cout << std::endl;
    return 0;
}

