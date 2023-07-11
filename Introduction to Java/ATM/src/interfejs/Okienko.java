// To do:
// okazjonalnie - okeinko PIN

package interfejs;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Okienko extends JFrame implements ActionListener {

    User A;
    ArrayList<User> users = new ArrayList<User>();
    ArrayList<ArrayList<String>> historia = new ArrayList<ArrayList<String>>();
    List ope;
    JScrollPane jScrollPane;

    JPanel front = new JPanel();
    JPanel verification = new JPanel();
    JPanel panelGlowny = new JPanel();
    JPanel konto = new JPanel();
    JPanel przelewy = new JPanel();
    JPanel pin = new JPanel();

    private final JTextField login;
    private final JTextField pass;
    private final JTextField capt_user;
    private final JTextField r_login;
    private final JTextField r_pass;
    private final JTextField val;
    private final JTextField acc_num;
    private final JTextField kw;
    private final JTextField tr_acc;
    private final JTextField p;
    private final JTextField v_p;
    private final JButton ack;
    private final JButton ok;
    private final JButton new_user;
    private final JButton pot;
    private final JButton back;
    private final JButton in;
    private final JButton out;
    private final JButton transfer;
    private final JButton back1;
    private final JButton back2;
    private final JButton back3;
    private final JButton balansuj;
    private final JButton acc_pin;
    private final JLabel t1;
    private final JLabel captcha;
    private final JLabel dane;
    private final JLabel acc_n;
    private final JLabel acc_i;
    private final JLabel ping;
    private final JLabel ac_p;

    private int curr_index;

    private String l1;
    private String p1;
    private String r_l1;
    private String r_p1;

    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");

    public Okienko()  {
        setLayout(new BorderLayout());
        setContentPane(new JLabel(new ImageIcon("C:\\Users\\lefik\\Desktop\\Studia\\Semestr IV\\Java\\Zajecia\\projekt10\\tlo2.png")));
        setLayout(new FlowLayout());
        setSize(700,500);

        front.setLayout(new GridBagLayout());
        front.setBackground(new Color(255, 255, 255, 170));
        verification.setLayout(new GridBagLayout());
        verification.setBackground(new Color(255, 255, 255, 170));
        panelGlowny.setLayout(new GridBagLayout());
        panelGlowny.setBackground(new Color(255, 255, 255, 170));
        konto.setLayout(new GridBagLayout());
        konto.setBackground(new Color(255, 255, 255, 170));
        przelewy.setLayout(new GridBagLayout());
        przelewy.setBackground(new Color(255, 255, 255, 170));
        pin.setLayout(new GridBagLayout());
        pin.setBackground(new Color(255, 255, 255, 170));

        GridBagConstraints c = new GridBagConstraints();
        c.fill = GridBagConstraints.HORIZONTAL;
        c.insets = new Insets(3,3,3,3);
        t1 = new JLabel("Podaj login i hasło");
        c.gridy = 0;
        c.gridx = 0;
        front.add(t1, c);

        login = new JTextField("");
        login.setPreferredSize(new Dimension(80, 24));
        c.gridy = 0;
        c.gridx = 1;
        front.add(login, c);

        pass = new JTextField("");
        pass.setPreferredSize(new Dimension(80, 24));
        c.gridy = 0;
        c.gridx = 2;
        front.add(pass, c);

        ok = new JButton("Zaloguj");
        ok.addActionListener(this);
        c.gridy = 1;
        c.gridx = 1;
        front.add(ok, c);

        new_user = new JButton("Zarejestruj");
        new_user.addActionListener(this);
        c.gridy = 1;
        c.gridx = 2;
        front.add(new_user, c);

        JLabel i1 = new JLabel("Imie");
        c.gridy = 0;
        c.gridx = 0;
        verification.add(i1, c);
        JLabel i2 = new JLabel("Nazwisko");
        c.gridy = 0;
        c.gridx = 2;
        verification.add(i2, c);
        JLabel i3 = new JLabel("6 cyfrowy numer konta");
        c.gridy = 0;
        c.gridx = 4;
        verification.add(i3, c);

        r_login = new JTextField("");
        r_login.setPreferredSize(new Dimension(80, 24));
        c.gridy = 1;
        c.gridx = 0;
        c.gridwidth = 2;
        verification.add(r_login, c);

        JLabel x = new JLabel("   ");
        c.gridy = 1;
        c.gridx = 1;
        c.gridwidth = 1;
        verification.add(x, c);

        r_pass = new JTextField("");
        r_pass.setPreferredSize(new Dimension(80, 24));
        c.gridy = 1;
        c.gridx = 2;
        c.gridwidth = 2;
        verification.add(r_pass, c);

        JLabel x1 = new JLabel("");
        c.gridy = 1;
        c.gridx = 3;
        c.gridwidth = 1;
        verification.add(x1, c);

        acc_num = new JTextField("");
        acc_num.setPreferredSize(new Dimension(80,24));
        c.gridy = 1;
        c.gridx = 4;
        c.gridwidth = 2;
        verification.add(acc_num, c);

        JLabel x2 = new JLabel("");
        c.gridy = 1;
        c.gridx = 5;
        c.gridwidth = 1;
        verification.add(x1, c);

        captcha = new JLabel("");
        c.gridy = 2;
        c.gridx = 2;
        verification.add(captcha, c);

        capt_user = new JTextField("");
        capt_user.setPreferredSize(new Dimension(80, 24));
        c.gridy = 2;
        c.gridx = 3;
        verification.add(capt_user, c);

        pot = new JButton("Zatwierdź");
        pot.addActionListener(this);
        c.gridy = 3;
        c.gridx = 0;
        c.gridwidth = 3;
        verification.add(pot, c);

        back = new JButton("Powrót");
        back.addActionListener(this);
        c.gridy = 3;
        c.gridx = 3;
        c.gridwidth = 3;
        verification.add(back, c);

        v_p = new JTextField("");
        v_p.setPreferredSize(new Dimension(80, 24));
        c.gridy = 2;
        c.gridx = 5;
        c.gridwidth = 1;
        verification.add(v_p, c);

        ac_p = new JLabel("PIN");
        c.gridx = 4;
        verification.add(ac_p, c);

        JLabel t2 = new JLabel("Co chcesz zrobić? Wybierz operację: ");
        c.gridy = 0;
        c.gridx = 0;
        c.gridwidth = 1;
        panelGlowny.add(t2, c);

        in = new JButton("Wpłać");
        in.addActionListener(this);
        c.gridy = 0;
        c.gridx = 1;
        panelGlowny.add(in, c);

        out = new JButton("Wypłać");
        out.addActionListener(this);
        c.gridy = 0;
        c.gridx = 2;
        panelGlowny.add(out, c);

        val = new JTextField("");
        val.setPreferredSize(new Dimension(50, 24));
        c.gridy = 0;
        c.gridx = 3;
        panelGlowny.add(val, c);

        ope = new List();
        jScrollPane = new JScrollPane(ope);
        jScrollPane.setPreferredSize(new Dimension(300, 100));
        c.gridy = 2;
        c.gridx = 0;
        c.gridwidth = 4;
        panelGlowny.add(jScrollPane, c);

        back1 = new JButton("Powrót");
        back1.addActionListener(this);
        c.gridy = 3;
        c.gridx = 0;
        panelGlowny.add(back1, c);

        dane = new JLabel("");
        c.gridy = 0;
        c.gridx = 1;
        c.gridwidth = 1;
        konto.add(dane, c);

        transfer = new JButton("Przelew");
        transfer.addActionListener(this);
        c.gridy = 1;
        c.gridx = 0;
        konto.add(transfer, c);

        back2 = new JButton("Wyloguj");
        back2.addActionListener(this);
        c.gridy = 1;
        c.gridx = 2;
        konto.add(back2, c);

        balansuj = new JButton("Balansuj");
        balansuj.addActionListener(this);
        c.gridy = 1;
        c.gridx = 1;
        konto.add(balansuj, c);

        back3 = new JButton("Powrót");
        back3.addActionListener(this);
        c.gridx = 0;
        c.gridy = 2;
        przelewy.add(back3, c);

        acc_n = new JLabel("Podaj numer konta na które chcesz przelać pieniądze: ");
        c.gridx = 0;
        c.gridy = 0;
        przelewy.add(acc_n, c);

        tr_acc = new JTextField("");
        tr_acc.setPreferredSize(new Dimension(80,24));
        c.gridx = 1;
        c.gridy = 0;
        c.gridwidth = 2;
        przelewy.add(tr_acc, c);

        acc_i = new JLabel("Ile pieniędzy chcesz przelać: ");
        c.gridx = 0;
        c.gridy = 1;
        przelewy.add(acc_i, c);

        kw = new JTextField("");
        kw.setPreferredSize(new Dimension(80,24));
        c.gridx = 1;
        c.gridy = 1;
        c.gridwidth = 2;
        przelewy.add(kw, c);

        ack = new JButton("Akceptuj");
        ack.addActionListener(this);
        c.gridx = 1;
        c.gridy = 2;
        c.gridwidth = 2;
        przelewy.add(ack, c);

        p = new JTextField("");
        p.setPreferredSize(new Dimension(80,24));
        c.gridy = 1;
        c.gridx = 0;
        pin.add(p, c);

        acc_pin = new JButton("Zatwierdź");
        acc_pin.addActionListener(this);
        c.gridy = 2;
        c.gridx = 0;
        pin.add(acc_pin, c);

        ping = new JLabel("Podaj pin");
        c.gridy = 0;
        c.gridx = 0;
        pin.add(ping, c);

        add(front);
        add(verification);
        add(panelGlowny);
        add(konto);
        add(przelewy);
        add(pin);

        panelGlowny.setVisible(false);
        verification.setVisible(false);
        konto.setVisible(false);
        przelewy.setVisible(false);
        pin.setVisible(false);

        try {
            File myObj = new File("baza.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                    String d0 = "", d1 = "", d2 = "", d3 = "", d4;
                    double dd2 = 0;
                    int dd3 = 0, dd4 = 0;

                         d0 = myReader.next();

                         d1 = myReader.next();
                         d2 = myReader.next();
                         dd2 = Double.parseDouble(d2);
                         d3 = myReader.next();
                         dd3 = Integer.parseInt(d3);
                         d4 = myReader.next();
                         dd4 = Integer.parseInt(d4);

                    A = new User(d0, d1, dd2, dd3 ,dd4);
                    System.out.println(A.getName() + " " + A.getForname() + " " + A.getAcc_balance() + " " + A.getAcc_number() + " "+ A.getPin());
                    users.add(A);
                }

            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        for (int i = 0; i < users.size(); i++) {
            historia.add(new ArrayList<String>());
        }

        int l12 = 0;
        while (l12 < users.size()) {
            try {
                File box = new File("story" + l12 + ".txt");
                Scanner myReader = new Scanner(box);
                while (myReader.hasNextLine()) {
                        historia.get(l12).add(myReader.nextLine());
                }
                l12++;
                myReader.close();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ok) {
            l1 = login.getText();
            p1 = pass.getText();

            boolean k = false;
            for (int i = 0; i < users.size(); i++) {
              if (l1.equals(users.get(i).getName()) && p1.equals(users.get(i).getForname())) {
                  curr_index = i;
                  front.setVisible(false);
                  pin.setVisible(true);
                  dane.setText("Witaj, " + users.get(curr_index).getName() + " " + users.get(curr_index).getForname() + " " + users.get(curr_index).getAcc_balance());
                  login.setText("");
                  pass.setText("");

                  k = true;
                  break;
              }
            }
            if (k == false) {
                JOptionPane.showMessageDialog(null, "Nie ma takiego użytkownika w bazie!",
                        "Informacja", JOptionPane.CLOSED_OPTION);
            }
        }

        if(e.getSource() == new_user){
            front.setVisible(false);
            verification.setVisible(true);
            Random gen = new Random();

            String[] tab1 = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j","k", "l", "m", "n", "o", "p",
                    "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
                    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                    "K", "L", "M", "N", "O", "P","Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

            captcha.setText(tab1[gen.nextInt(52)] + tab1[gen.nextInt(52)]+ tab1[gen.nextInt(52)]+ tab1[gen.nextInt(52)]
                    + tab1[gen.nextInt(52)]+ tab1[gen.nextInt(52)]);
        }

        if(e.getSource() == pot) {
            String temp, tamp, acc, a;
            temp = capt_user.getText();
            tamp = captcha.getText();

            r_l1 = r_login.getText();
            r_p1 = r_pass.getText();
            acc = acc_num.getText();
            int g = Integer.parseInt(acc);
            a = v_p.getText();
            int p = Integer.parseInt(a);

            boolean ex = false;
            for (int i = 0; i < users.size(); i++) {
                if (g == users.get(i).getAcc_number()) {
                    JOptionPane.showMessageDialog(null, "Podany numer konta już istnieje!!",
                            "Informacja", JOptionPane.CLOSED_OPTION);
                    ex = true;
                    break;
                }
                if (p == users.get(i).getPin()){
                    JOptionPane.showMessageDialog(null, "Podany numer PIN już istnieje!!",
                            "Informacja", JOptionPane.CLOSED_OPTION);
                    ex = true;
                    break;
                }
            }
            if (ex == false) {
                if (acc.length() == 6) {
                    if (a.length() == 4) {
                        if (temp.equals(tamp)) {
                            front.setVisible(true);
                            verification.setVisible(false);

                            r_login.setText("");
                            r_pass.setText("");
                            capt_user.setText("");
                            acc_num.setText("");

                            A = new User(r_l1, r_p1, 0, g, p);
                            users.add(A);

                            historia.add(new ArrayList<String>());

                            try {
                                FileWriter myWriter = new FileWriter("baza.txt", true);
                                myWriter.write("\n" + users.get(users.size() - 1).getName() + " " + users.get(users.size() - 1).getForname() + " " + users.get(users.size() - 1).getAcc_balance()
                                        + " " + users.get(users.size() - 1).getAcc_number() + " " + users.get(users.size() - 1).getPin());
                                myWriter.close();
                                int s = users.size()-1;
                                FileWriter myWrite = new FileWriter("story" + s + ".txt");
                                myWrite.write("");
                                myWrite.close();
                                System.out.println("Successfully wrote to the file.");
                            } catch (IOException u) {
                                System.out.println("An error occurred.");
                                u.printStackTrace();
                            }
                        } else {
                            JOptionPane.showMessageDialog(null, "Niepoprawny kod captcha!",
                                    "Informacja", JOptionPane.CLOSED_OPTION);
                        }
                    }else {
                        JOptionPane.showMessageDialog(null, "Podaj 4cyfrowy pin nie zaczynający sie od 0!",
                                "Informacja", JOptionPane.CLOSED_OPTION);
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "Podaj 6 cyfrowy numer rachunku!",
                            "Informacja", JOptionPane.CLOSED_OPTION);
                }
            }
        }

        if(e.getSource() == back) {
            front.setVisible(true);
            verification.setVisible(false);
            ope.removeAll();
        }

        if(e.getSource() == in) {
            LocalDateTime now = LocalDateTime.now();
            String dod = val.getText();
            double dodaj = Double.parseDouble(dod);
            double g = users.get(curr_index).getAcc_balance();
            double fin = dodaj + g;
            users.get(curr_index).setAcc_balance(fin);
            System.out.println(users.get(curr_index).getAcc_balance());
            val.setText("");
            historia.get(curr_index).add(dtf.format(now) + " Wpłacono: " + dod + " Stan twojego konta wynosi: " + users.get(curr_index).getAcc_balance());
            ope.add(historia.get(curr_index).get(historia.get(curr_index).size() - 1));
        }

        if(e.getSource() == out) {
            LocalDateTime now = LocalDateTime.now();
            String dod = val.getText();
            double dodaj = Double.parseDouble(dod);
            double g = users.get(curr_index).getAcc_balance();
            double fin = g - dodaj;
            if (g >= dodaj) {
                users.get(curr_index).setAcc_balance(fin);
                System.out.println(users.get(curr_index).getAcc_balance());
                val.setText("");
                historia.get(curr_index).add(dtf.format(now) + " Wypłacono: " + dod + " Stan twojego konta wynosi: " + users.get(curr_index).getAcc_balance());
                ope.add(historia.get(curr_index).get(historia.get(curr_index).size() - 1));
            } else {
                JOptionPane.showMessageDialog(null, "Brak możliwych środków do wypłaty na koncie",
                 "Informacja", JOptionPane.CLOSED_OPTION);
            }
        }

        if(e.getSource() == back1) {
            panelGlowny.setVisible(false);
            konto.setVisible(true);
            val.setText("");
            ope.removeAll();
            dane.setText("Witaj " + users.get(curr_index).getName() + " " + users.get(curr_index).getForname() + " " + users.get(curr_index).getAcc_balance());

                try {
                        FileWriter box = new FileWriter("story" + curr_index + ".txt");
                            for (int j = 0; j < historia.get(curr_index).size(); j++) {
                                box.write(String.valueOf(historia.get(curr_index).get(j) + "\n"));
                            }
                            box.close();
                } catch(IOException a){
                    a.printStackTrace();
                }
            }


        if(e.getSource() == back2) {
            konto.setVisible(false);
            front.setVisible(true);

            try {
                FileWriter myWriter = new FileWriter("baza.txt");
                for (int i = 0; i < users.size(); i++) {
                    if (i == users.size() - 1) {
                        myWriter.write(users.get(i).getName() + " " + users.get(i).getForname() + " " + users.get(i).getAcc_balance()
                                + " " + users.get(i).getAcc_number() + " " + users.get(i).getPin());
                    } else {
                        myWriter.write(users.get(i).getName() + " " + users.get(i).getForname() + " " + users.get(i).getAcc_balance()
                                + " " + users.get(i).getAcc_number() + " " + users.get(i).getPin()+ "\n");
                    }
                }
                myWriter.close();
                System.out.println("Successfully wrote to the file.");
            } catch (IOException u) {
                System.out.println("An error occurred.");
                u.printStackTrace();
            }
        }

        if(e.getSource() == balansuj) {
            konto.setVisible(false);
            panelGlowny.setVisible(true);
            for (int i = 0; i < historia.get(curr_index).size(); i++) {
                ope.add(historia.get(curr_index).get(i));
            }
        }

        if (e.getSource() == transfer) {
            przelewy.setVisible(true);
            konto.setVisible(false);
        }

        if(e.getSource() == back3) {
            przelewy.setVisible(false);
            konto.setVisible(true);
            tr_acc.setText("");
            kw.setText("");
        }

        if(e.getSource() == ack) {
            String b = tr_acc.getText();
            int d = Integer.parseInt(b);
            String c = kw.getText();
            double c1 = Double.parseDouble(c);
            boolean ifSucceded = false;
            LocalDateTime now = LocalDateTime.now();

            tr_acc.setText("");
            kw.setText("");
            for (int i = 0; i < users.size(); i++) {
               if(d != users.get(curr_index).getAcc_number()) {
                   if (d == users.get(i).getAcc_number()) {
                       if (users.get(curr_index).getAcc_balance() >= c1) {

                           users.get(i).setAcc_balance(users.get(i).getAcc_balance() + c1);
                           users.get(curr_index).setAcc_balance(users.get(curr_index).getAcc_balance() - c1);

                           historia.get(curr_index).add(dtf.format(now) + " Przelano: " + c1 + " Na konto: " + users.get(i).getAcc_number() + "\n Stan twojego konta wynosi: " + users.get(curr_index).getAcc_balance());
                           historia.get(i).add(dtf.format(now) + " Przelano: " + c1 + " Z konta: " + users.get(curr_index).getAcc_number() + "\n Stan twojego konta wynosi: " + users.get(i).getAcc_balance());

                           dane.setText("Witaj " + users.get(curr_index).getName() + " " + users.get(curr_index).getForname() + " " + users.get(curr_index).getAcc_balance());
                           JOptionPane.showMessageDialog(null, "Środki zostały przelane",
                                   "Informacja", JOptionPane.CLOSED_OPTION);
                           ifSucceded = true;
                           break;
                       } else {
                           JOptionPane.showMessageDialog(null, "Brak wystarczających środków na koncie!",
                                   "Informacja", JOptionPane.CLOSED_OPTION);
                           break;
                       }
                   }
               } else {
                   JOptionPane.showMessageDialog(null, "Podano własny numer konta!",
                           "Informacja", JOptionPane.CLOSED_OPTION);
                   ifSucceded = true;
                   break;
               }
            }

            if (ifSucceded == false){
                JOptionPane.showMessageDialog(null, "Nie ma takiego konta jak " + b,
                        "Informacja", JOptionPane.CLOSED_OPTION);
            }

        }

        if(e.getSource() == acc_pin) {
            String a;
            int s;
            a = p.getText();
            s = Integer.parseInt(a);

            for (int i = 0; i < users.size(); i++) {
                if (users.get(i).getPin() == s) {
                    curr_index = i;
                    dane.setText("Witaj, " + users.get(curr_index).getName() + " " + users.get(curr_index).getForname() + " " + users.get(curr_index).getAcc_balance());
                    konto.setVisible(true);
                    pin.setVisible(false);
                    p.setText("");
                    break;
                }
            }
        }
    }
}
