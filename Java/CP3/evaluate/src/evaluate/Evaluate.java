/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evaluate;

import java.util.*;
import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;
/**
 *
 * @author Return One
 */
public class Evaluate {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        ScriptEngineManager mgr = new ScriptEngineManager();
        ScriptEngine engine = mgr.getEngineByName("JavaScript");
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) System.out.println(engine.eval(sc.nextLine()));
    }
    
}
