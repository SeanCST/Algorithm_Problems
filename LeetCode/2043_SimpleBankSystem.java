class Bank {

    private long[] balanceArr;
    private int n;
    
    public Bank(long[] balance) {
        balanceArr = balance;
        n = balanceArr.length;
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if(account1 <= n && account2 <= n && withdraw(account1, money)) {
            return deposit(account2, money);
        } else {
            return false;
        }
    }
    
    public boolean deposit(int account, long money) {
        if(account <= n) {
            balanceArr[account - 1] += money;
            return true;
        } else {
            return false;
        }
    }
    
    public boolean withdraw(int account, long money) {
        if(account > n || balanceArr[account - 1] < money) {
            return false;
        } else {
            balanceArr[account - 1] -= money;
            return true;
        }
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */