/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package determine_the_day;

import java.lang.String;
import java.util.Calendar;
import java.util.GregorianCalendar;
/**
 *
 * @author Return One
 */
public class Determine_the_day {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String[] names = new String[]
        { "", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        Calendar calendar = new GregorianCalendar(2010, 7, 9);
        System.out.println(names[calendar.get(Calendar.DAY_OF_WEEK)]);
    }
    
}
