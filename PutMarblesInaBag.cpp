class Solution {
public:
     vector<vector<int>> getIntervals() {
          map<int, int> _map;
        vector<vector<int>> intervals;
        for(auto const & p : _map)
            intervals.push_back({p.first, p.second});
        return intervals;
    }
    void smjre_ho_bhai(vector<long long int>&mai_hun_kon,int &helpful){
         // for(long long int i = 0;i<helpful.size()-1;i++){mai_hun_kon.push_back(helpful[i]+helpful[i+1]);}
    }
    
    int jumpSearch(int arr[], int x, int n)
{
    // Finding block size to be jumped
    int step = sqrt(n);
  
    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
  
    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;
  
        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;
  
    return -1;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
   void updte( vector<long long int>&mai_hun_kon,vector<long long int>&gorilla_bhai){
          sort(mai_hun_kon.begin() , mai_hun_kon.end() , greater<long long int>());
          sort(gorilla_bhai.begin() , gorilla_bhai.end());
   }
    int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
 
    long long int putMarbles(vector<int>& helpful, int tol_txming) {
        
          if(tol_txming == 1 || tol_txming == helpful.size()) return 0;
         
        
          long long int pahela_utar = 0;
        
         long long int dusra_badmash = 0;
           tol_txming--;
        
         vector<long long int>mai_hun_kon;
        
        // smjre_ho_bhai(mai_hun_kon,helpful);
        
          for(long long int i = 0;i<helpful.size()-1;i++){mai_hun_kon.push_back(helpful[i]+helpful[i+1]);}

        
             vector<long long int>gorilla_bhai;
        
          for(long long int i = 0;i<helpful.size()-1;i++){gorilla_bhai.push_back(helpful[i]+helpful[i+1]);}
        
        updte(mai_hun_kon,gorilla_bhai);
        
        
            for(long long int i =0;i<tol_txming;i++) dusra_badmash += mai_hun_kon[i];
        
        for(long long int i =0;i<tol_txming;i++) pahela_utar += gorilla_bhai[i];
        
        
        return (dusra_badmash - pahela_utar);
        
                 
        
    }
    
    void addNum(int value) {
        map<int,int>_map;
        auto it = _map.lower_bound(value);
        bool merged = false;
        if(it != _map.begin()) {
            auto prev = it;
            --prev;
            if(prev->second + 1 >= value) {
                merged = true;
                prev->second = max(prev->second, value);
            }
        }

        if(it != _map.end()) {
            if(it->first - 1 <= value) {
                if(merged) {
                    auto prev = it;
                    --prev;
                    if(prev->second >= it->first - 1) {
                        prev->second = max(prev->second, it->second);
                        _map.erase(it);
                    }
                } else {
                    merged = true;
                    if(it->first != value) {
                        pair<int, int> p = *it;
                        p.first = min(p.first, value);
                        it = _map.insert(it, p);
                        ++it;
                        if(it != _map.end())
                            _map.erase(it);
                    }
                }
            }
        }
        if(!merged)
            _map.insert(it, {value, value});
    }
};
