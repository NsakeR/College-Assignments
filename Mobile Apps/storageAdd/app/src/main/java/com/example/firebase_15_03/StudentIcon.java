package com.example.firebase_15_03;

public class StudentIcon extends Student{
    String icon;//path to icon in Storage

    public StudentIcon(){}

    public StudentIcon(String icon) {
        this.icon = icon;
    }

    public StudentIcon(String firstName, String lastName, double tinder, int val, String icon) {
        super(firstName, lastName, tinder, val);
        this.icon = icon;
    }

    public String getIcon() {
        return icon;
    }

    public void setIcon(String icon) {
        this.icon = icon;
    }
}
