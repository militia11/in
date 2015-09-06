/**
 * 
 */
package serverApplicationTests;

/**
 * Import Sikuli
 */
import org.sikuli.basics.*;
import org.sikuli.script.*;

/**
 * Import JUnit
 */
import static org.junit.Assert.*;
import org.junit.*;

import java.lang.Thread.State;

import java.util.Scanner;
import static org.junit.Assert.*;

import org.junit.Test;

public class InitTest {
	//Computer screen object
	private Screen screen;
		
	// Text next to found position
	private String recogniseText;
		
	// Target fields
	private Pattern targetTerminal;	
	private Pattern targetServerApp;
	
	/**
	 * @throws java.lang.Exception
	 */
	@Before
	public void setUp() throws Exception { 
			Settings.OcrTextRead = true;
			Settings.OcrTextSearch = true;	 
            
			screen = new Screen();
            targetTerminal = new Pattern("./images/1441451200391.png");
            targetServerApp = new Pattern("./images/1441462826632.png");
	}

	/**
	 * @throws java.lang.Exception
	 */
	@After
	public void tearDown() throws Exception {
	}
	
	@Test
	public void testOpenApp() throws InterruptedException {
//		@SuppressWarnings("resource")
//		Scanner userInput = new Scanner(System.in);
//	    System.out.print("Please enter full path to " + "\n" + "Android Photos Archive executable file" + "\n" + "PATH=");
//	    String path = userInput.next();
//	  
//	    Thread.sleep(100);
	    
	    screen.type("t", KeyModifier.CTRL + KeyModifier.ALT); //openApp("gnome-terminal")
	    
	    Thread.sleep(50);
	    
	    try {
			screen.click(targetTerminal);  
		} catch (FindFailed e) {
			System.out.print("Can't find open Terminal");
			fail();
			// ZATRZYMANIE TESTOW !!!!!!!!!!111
		}	//   path	    
	    
	    				//path
	    screen.type("cd " + "~/build-SynchronizationTool-Desktop-Release/ServerApplication/src/app/" + Key.ENTER );
		screen.type("./app"+ Key.ENTER );
		
		Thread.sleep(50);
		
		try {
			screen.find(targetServerApp);  
		} catch (FindFailed e) {
			System.out.print("Can't run Android Photo Archive. Please check path and make sure executable file exist");
			fail();
			// ZATRZYMANIE TESTOW !!!!!!!!!!111
		}
	}
}