## C++

```c++
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */
 
bool isDiffBiggerThanThree(int n){
    int diff = n % 5;
    return diff >= 3;
}

vector<int> gradingStudents(vector<int> grades) {
    vector<int> ans;
    for(int grade : grades){
        if(grade < 38) {
            ans.push_back(grade);
            continue;
        } 
        
        if(isDiffBiggerThanThree(grade)){
            grade += 5 - (grade % 5);
        }
        ans.push_back(grade);
    }
    return ans;
}
```

## java

```java
    private static boolean isDiffBiggerThanThree(int grade) {
        int diff = grade % 5;
        return diff >= 3;
    }

    public static List<Integer> gradingStudents(List<Integer> grades) {
        // Write your code here
        List<Integer> answer = new ArrayList<>();
        for (int grade : grades) {
            if (grade >= 38 && isDiffBiggerThanThree(grade)) {
                grade += 5 - (grade % 5);
            }
            answer.add(grade);
        }

        return answer;
    }
```