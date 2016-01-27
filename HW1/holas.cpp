#include <iostream>
#include <map>

using namespace std;

int main(){
    // init
    int n, m, card_val1, card_val2, idx1, idx2;
    cin >> n >> m;
    map<int, int> indexes;
    map<int, int>::iterator iter1, iter2;
    // execute swaps
    for(int swap_count = 0; swap_count < m; swap_count++){
        cin >> card_val1 >> card_val2;
        // find index of card with value card_val1
        card_val1 -= swap_count;
        iter1 = indexes.find(card_val1);
        if(iter1 == indexes.end()){ idx1 = card_val1; }
        else{ idx1 = iter1->second; }
        // find index of card with value card_val2
        card_val2 -= swap_count;
        iter2 = indexes.find(card_val2);
        if(iter2 == indexes.end()){ idx2 = card_val2; }
        else{ idx2 = iter2->second; }
        
        // swap
        if(iter1 != indexes.end()){ iter1->second = idx2; }
        else{ indexes[card_val1] = idx2; }
        if(iter2!= indexes.end()){ iter2->second = idx1; }
        else{ indexes[card_val2] = idx1; }
    }    
    // finalize
    map<int, int> values;
    for(map<int, int>::iterator it = indexes.begin(); it != indexes.end(); it++){
        values[it->second] = it->first;
    }
    map<int, int>::iterator it;
    int idx;
    for(int i = 1; i <= n; i++){
        it = values.find(i);
        if(it != values.end()){ idx = it->second; }
        else{ idx = i; }
        if(i == 1){
            cout << (idx + m);
        }
        else{
            cout << ' ' << (idx + m);
        }
    }    
    cout << endl;
    return 0;
}