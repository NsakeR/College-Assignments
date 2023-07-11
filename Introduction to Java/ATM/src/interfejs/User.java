package interfejs;

public class User {

    private String name;
    private String forname;
    private double acc_balance;

    public int getPin() {
        return pin;
    }

    public void setPin(int pin) {
        this.pin = pin;
    }

    private int pin;

    public int getAcc_number() {
        return acc_number;
    }

    public void setAcc_number(int acc_number) {
        this.acc_number = acc_number;
    }

    private int acc_number;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getForname() {
        return forname;
    }

    public void setForname(String forname) {
        this.forname = forname;
    }

    public double getAcc_balance() {
        return acc_balance;
    }

    public void setAcc_balance(double acc_balance) {
        this.acc_balance = acc_balance;
    }

    public User (String name, String forname, double k, int num, int pin) {
        this.name = name;
        this.forname = forname;
        this.acc_balance = k;
        this.acc_number = num;
        this.pin = pin;
    }
}
