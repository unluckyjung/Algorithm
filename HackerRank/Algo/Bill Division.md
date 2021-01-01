## c++

```c++
void bonAppetit(vector<int> bill, int notAteIndex, int amountPaid) {
    int needPayMoney = 0;
    for(int i = 0 ;  i < (int)bill.size(); ++i){
        if(i == notAteIndex) continue;
        needPayMoney += bill[i];
    }
    needPayMoney /= 2;
    
    int refundMoney = amountPaid - needPayMoney;
    if(refundMoney == 0){
        cout << "Bon Appetit";
        return;
    }
    cout << refundMoney;
}
```