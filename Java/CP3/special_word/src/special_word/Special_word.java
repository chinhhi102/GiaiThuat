/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package special_word;

import java.lang.*;

/**
 *
 * @author Return One
 */
public class Special_word {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String S = "line: a70 and z72 will be replace, aa24 and a872 will not";
        System.out.println(S.replaceAll("(^| )+[a-z][0-9][0-9][0-9]( |$)+", " *** "));
    }
    
}
