class Solution {
public:
    void duplicateZeros(vector<int>& a, int i = 0, int sh = 0) {
  for (i = 0; sh + i < a.size(); ++i) sh += a[i] == 0;
  for (i = i - 1; sh > 0; --i) {
    if (i + sh < a.size()) a[i + sh] = a[i];
    if (a[i] == 0) a[i + --sh] = a[i];
  }
}
};