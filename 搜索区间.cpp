//给定一个包含 n 个整数的排序数组，找出给定目标值 target 的起始和结束位置。

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
   template<class T, class V>
   T _lower_bound(T first, T last, const V & value){
        int len = last - first;
        int half;
        T middle;
        while(len > 0){
            half = len >> 1;
            middle = first + half;
            if(*middle < value){
                first = middle + 1;
                len = len - half - 1;
            }
            else
                len = half;
        }
        return first;
    }
    template <class T, class V>
    T _upper_bound(T first, T last, const V & value){
        int len = last - first;
        int half;
        T middle;
        while(len > 0){
            half = len >> 1;
            middle = first + half;
            if(*middle > value){
                len = half;
            }
            else{
                first = middle + 1;
                len = len - half - 1;
            }
        }
        return first;
    }
    
    template<class T, class V>
    pair<T, T> _equal_range(T first, T last, const V & value){
        int len = last - first;
        int half;
        T middle, left, right;
        while(len > 0){
            half = len >> 1;
            middle = first + half;
            if(*middle < value){
                first = middle + 1;
                len = len - half - 1;
            }
            else if(*middle > value){
                len = half;
            }
            else{
                left = _lower_bound(first, middle, value);
                right = _upper_bound(++middle, first + len, value);
                return pair<T, T>(left, right);
            }
        }
        return pair<T, T>(first, first);
    }
    vector<int> searchRange(vector<int> &A, int target) {

        if(A.empty() ) return {-1, -1};
        auto a = _equal_range(A.begin(), A.end(), target);
        if(a.first == a.second ) return {-1, -1};
        else
            return {a.first - A.begin(),  a.second - 1 - A.begin() };
        
    }
}; 
