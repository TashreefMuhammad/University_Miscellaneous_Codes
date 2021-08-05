package producerconsumerproblem;

import javax.swing.JDialog;
import javax.swing.JOptionPane;


public class Stopping implements Runnable{

    @Override
    public void run() {
        // The JOptionPane which will help user control when to stop the code
        final JDialog dialog = new JDialog();
        dialog.setAlwaysOnTop(true);
        JOptionPane.showMessageDialog(dialog, "Closing this will cause the program to stop");
        System.exit(0);
    }
}
