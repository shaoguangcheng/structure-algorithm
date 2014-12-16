/*
The code base version is an integer and start from 1 to n.
One day, someone commit a bad version in the code case, so 
it caused itself and the following versions are all failed 
in the unit tests.
*/

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here

        int l = 1, r = n, m;
        while(l < r){
            m = (l + r)/2;
            if(VersionControl::isBadVersion(m)){
                if(m >0 && !VersionControl::isBadVersion(m-1))
                    return m;
                else
                    r = m - 1;
            }
            else{
                l = m + 1;
            }            
        }
        return (l+r)/2;
    }
};
