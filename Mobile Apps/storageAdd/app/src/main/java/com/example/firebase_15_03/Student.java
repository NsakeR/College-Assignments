package com.example.firebase_15_03;

public class Student {

    String firstName;
    String lastName;

    double tinder;
    int val;


    public Student() {
    }

    public Student(String firstName, String lastName, double tinder, int val) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.tinder = tinder;
        this.val = val;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public double getTinder() {
        return tinder;
    }

    public void setTinder(double tinder) {
        this.tinder = tinder;
    }

    public int getVal() {
        return val;
    }

    public void setVal(int val) {
        this.val = val;
    }
}
