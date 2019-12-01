/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package decimal;

import java.util.Scanner;
/**
 *
 * @author Return One
 */
public class Decimal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        double d = sc.nextDouble();
        System.out.printf("%7.3f\n",d);
    }
}
