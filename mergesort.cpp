#include <iostream>
#include <vector>

using namespace std;

vector<int> readarray()
{
    vector<int> g;
    int tmp;
    while(std::cin.good()){
        std::cin >> tmp;
        g.push_back(tmp);
    }
    return g;
}

void print(vector<int> theNumbers)
{
    for (std::vector<int>::const_iterator i = theNumbers.begin(); i !=            theNumbers.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
}

vector<int> merge(vector<int> theNumbers, int l, int m, int r){
    
    int a,b,c;
    int s1 = m-l+1;
    int s2 = r-m;
    vector<int> L;
    vector<int> R;
    std::cout<< "this is numbers";
    print(theNumbers);
    for(int i = 0; i <s1; i++)
        L.push_back(theNumbers[l+i]);
    for(int j = 0; j <s2; j++)
        R.push_back(theNumbers[m+1+j]);
    print(L);
    print(R);
    
    a = 0;
    b = 0;
    c = l;
    
    while(a<s1 && b < s2){
        if(L[a] <= R[b]){
            theNumbers[c] = L[a];
            a++;
        }
        else{
            theNumbers[c] = R[b];
            b++;
        }
        c++;  
    }
    
    while(a<s1){
        theNumbers[c] = L[a];
        a++;
        c++;
    }
    while(b<s2){
        theNumbers[c] = R[b];
        b++;
        c++;
    }
    return theNumbers;
}
    
vector<int> sort(vector<int> theNumbers, int l, int r)
{
    if(l < r){
        int m = (l+r)/2;
        
        sort(theNumbers,l,m);
        sort(theNumbers,m+1,r);
        
        merge(theNumbers,l,m,r);
    }
    return theNumbers;
}

int main()
{
      vector<int> theData = readarray();
      theData = sort(theData,0,theData.size()-1);
      print(theData);  
}