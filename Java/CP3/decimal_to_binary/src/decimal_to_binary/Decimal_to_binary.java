/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package decimal_to_binary;

import java.lang.String;
import java.math.BigInteger;

/**
 *
 * @author Return One
 */
public class Decimal_to_binary {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String str = "FF";
        int X = 16, Y = 10;
        System.out.println(new BigInteger(str, X).toString(Y));
    }
    
}
