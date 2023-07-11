package interfejs;

import javax.swing.*;
import java.io.IOException;

public class Bankomat {
    public static void main (String[] args) throws IOException {
        Okienko siema = new Okienko();
        siema.setTitle("Bankomat banku Europex");
        siema.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        siema.setVisible(true);
        siema.setResizable(false);
    }
}
