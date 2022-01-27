#include<iostream>
#include<vector>
// Recursion By Striver : L7. All Kind of Patterns in Recursion | Print All | Print one | Count
// Printing Subsequence whose sum is K

// 1. Printing all Subsequences whose sum is K
void printAllSubsequence(int i, int arr[], int n, int k, int sum, std::vector<int> &ds){
    if(i == n){
        if(k == sum){
            for (auto x : ds){
                std::cout << x << " ";
            }
            std::cout << "\n";
        }
        return;
    }

    // Take
    ds.push_back(arr[i]);
    k += arr[i];
    printAllSubsequence(i+1, arr, n, k, sum, ds);
    k -= arr[i];
    ds.pop_back();

    // Not take
    printAllSubsequence(i+1, arr, n, k, sum, ds);
}

// OR 1. Printing all Subsequences whose sum is K - Optimized way using vector(less parameters)
void printAllSubsequence2(int i, std::vector<int> arr, int sum, std::vector<int> &ds){
    if(i == arr.size()){
        if(sum == 0){
            for (auto x : ds){
                std::cout << x << " ";
            }
            std::cout << "\n";
        }
        return;
    }

    // Take
    if(arr[i] <= sum){
        ds.push_back(arr[i]);
        printAllSubsequence2(i+1, arr, sum - arr[i], ds);
        ds.pop_back();
    }

    // Not Take
    printAllSubsequence2(i+1, arr, sum, ds);
}


// 2. Printing any one Subsequences whose sum is K
bool printOneSubsequence(int i, int arr[], int n, int k, int sum, std::vector<int> &ds){
    if(i == n){
        if(k == sum){
            for (auto x : ds){
                std::cout << x << " ";
            }
            return true;
        }
        else
            return false;
    }

    // Take
    ds.push_back(arr[i]);
    k += arr[i];
    if(printOneSubsequence(i+1, arr, n, k, sum, ds) == true)
        return true;
    
    k -= arr[i];
    ds.pop_back();

    // Not Take
    if(printOneSubsequence(i+1, arr, n, k, sum, ds) == true)
        return true;
    
    return false;
}

// OR 2. Printing any one Subsequences whose sum is K -optimized
bool printOneSubsequence2(int i, std::vector<int> arr, int sum, std::vector<int> &ds){
    if(i == arr.size()){
        if(sum == 0){
            for (auto x : ds){
                std::cout << x << " ";
            }
            return true;
        }
        else
            return false;
    }

    // Take
    if(arr[i] <= sum){
        ds.push_back(arr[i]);
        if(printOneSubsequence2(i+1, arr, sum - arr[i], ds) == true)
            return true;

        ds.pop_back();
    }

    // Not Take
    if(printOneSubsequence2(i+1, arr, sum, ds) == true)
        return true;
    
    return false;
}


// 3. Printing count of Subsequences whose sum is K
int countSubsequence(int i, int arr[], int n, int k, int sum){
    // One more condition strictly done when array conatins +ve integers
    if(k > sum)
        return 0;

    else if(i == n){
        if(k == sum)
            return 1;
        else
            return 0;
    }

    // Take - left side
    k += arr[i];
    int l = countSubsequence(i+1, arr, n, k, sum);
    k -= arr[i];

    // Not Take - right side
    int r = countSubsequence(i+1, arr, n, k, sum);

    return l+r;
}

// 3. Printing count of Subsequences whose sum is K
int countSubsequence2(int i, std::vector<int> arr, int sum){
    if(i == arr.size()){
        if(sum == 0)
            return 1;
        else
            return 0;
    }

    // Take - left side
    int l = countSubsequence2(i+1, arr, sum - arr[i]);

    // Not Take - right side
    int r = countSubsequence2(i+1, arr, sum);

    return l+r;
}


int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(int);
    int sum = 2;

    std::vector<int> ds;

    std::vector<int> arr2 = {1,2,1};

    //1.
    // printAllSubsequence(0, arr, n, 0, sum, ds);
    // std::cout << "\n";
    // printAllSubsequence2(0, arr2, sum, ds);

    //2.
    // if(printOneSubsequence(0, arr, n, 0, sum, ds))
    //     std::cout << "\n";
    // else
    //     std::cout << "Does not exist any sunsequence whose sum is " << sum;
    // std::cout << "\n";
    // // Run this individually as ds got updated
    if(printOneSubsequence2(0, arr2, sum, ds))
        std::cout << "\n";
    else
        std::cout << "Does not exist any sunsequence whose sum is " << sum;

    //3.
    // std::cout << countSubsequence(0, arr, n, 0, sum);
    // std::cout << countSubsequence2(0, arr2, sum);

    return 0;
}