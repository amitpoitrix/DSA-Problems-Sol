#include<iostream>

int eqIndex(std::string inputString, int n){
    int mid = n / 2;
    
    int sumLeft = 0;
    for (int i = 0; i < mid; i++){
        sumLeft += inputString[i];
    }

    int sumRight = 0;
    for (int i = mid+1; i < n; i++){
        sumRight += inputString[i];
    }
    
    if(sumLeft > sumRight){
        // Move Leftward till sumLeft <= sumRight
        while (sumLeft > sumRight && mid >= 1){
            sumLeft -= inputString[mid - 1];
            sumRight += inputString[mid];
            mid--;
        }
    }
    // sumLeft <= sumRight
    else{
        // Move Rightward till sumRight <= sumLeft
        while (sumLeft < sumRight && mid <= n-2){
            sumLeft += inputString[mid];
            sumRight -= inputString[mid + 1];
            mid++;
        }
    }

    if(sumLeft == sumRight){
        return mid;
    }
    else
        return -1;
}

int main(){
    std::string inputString;
    std::getline(std::cin, inputString);
    int n = inputString.size();
    std::cout << n << "\n";
    std::cout << eqIndex(inputString, n);
    
    return 0;
}