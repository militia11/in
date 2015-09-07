/**
 * 
 */
package serverApplicationTests;

/**
 * Import Sikuli
 */
import org.sikuli.basics.Settings;
import org.sikuli.basics.SikuliScript;
import org.sikuli.script.*;

/**
 * Import JUnit
 */
import static org.junit.Assert.*;

import org.junit.*;

import java.lang.Thread.State;

import java.util.Scanner;

public class DatabaseSettingsTests {
	//Server Application region object
	private Region regionServerApp;
			
	// Text next to found position
	private String recogniseText;
			
	// Target fields
	private Pattern targetServerApp;
	private Pattern targetSettings;	
	private Pattern targetDBConnection;
	private Pattern targetConnectionError;
	private Pattern targetMySqlDriver;
	private Pattern targetSqLiteDriver;
	private Pattern targetDriverLabel;
	private Pattern targetHostLabel;
	private Pattern targetUserLabel;
	private Pattern targetPasswordLabel;
	private Pattern targetDatabaseLabel;
	private Pattern targetOkButton;
	private Pattern targetCancelButton;
		
	/**
	* @throws java.lang.Exception
	*/
	@Before
	public void setUp() throws Exception { 
		Settings.OcrTextRead = true;
		Settings.OcrTextSearch = true;	 
		
		App.open("gnome-terminal");
		
		regionServerApp = App.focusedWindow();	    
	    Thread.sleep(800);

	    regionServerApp.type("cd .." + "cd app" + Key.ENTER );
		regionServerApp.type("./app"+ Key.ENTER );
		
		Thread.sleep(50);
		
		try {
			regionServerApp.find(targetServerApp);  
		} catch (FindFailed e) {
			System.out.print("Can't run Android Photo Archive. Please check path and make sure executable file exist");
			fail();
			// ZATRZYMANIE TESTOW !!!!!!!!!!111
		}
		
		targetServerApp = new Pattern("./images/1441462826632.png");
		targetSettings = new Pattern("./images/1441463959035.png");
		targetDBConnection = new Pattern("./images/114987846.png");
		targetConnectionError = new Pattern("./images/1441466153038.png");
		targetMySqlDriver = new Pattern("./images/1441466168272.png");
		targetSqLiteDriver = new Pattern("./images/1441466197772.png");
		targetDriverLabel = new Pattern("./images/1441466212864.png");
		targetHostLabel = new Pattern("./images/1441466235010.png");
		targetUserLabel = new Pattern("./images/1441466243744.png");
		targetPasswordLabel = new Pattern("./images/1441466257040.png");
		targetDatabaseLabel = new Pattern("./images/1441466276599.png");
		targetOkButton = new Pattern("./images/1441466285584.png");
		targetCancelButton = new Pattern("./images/1441466293670.png");		
	}
	/**
	 * @throws java.lang.Exception
	 */
	@After
	public void tearDown() throws Exception {
		App.close("app");
		regionServerApp.type(Key.F4 + KeyModifier.ALT);
		regionServerApp.type(Key.ENTER);
	}
	
//	@Test
//	public void testCheckSetSqLiteParameters()  throws FindFailed{				
//	    try {
//			screen.click(targetSettings);  
//		} catch (FindFailed e) {
//			System.out.print("Can't find 'Ustawienia' ");
//			fail();
//		}	    
//		
//		try {
//			screen.click(targetDBConnection);  
//		} catch (FindFailed e) {
//			System.out.print("Can't find 'Połączenie z bazą danych'");
//			fail();
//		}
//		
//		boolean sqLiteDrv = true;
//		
//		try {
//			screen.find(targetSqLiteDriver);  
//		} catch (FindFailed e) {
//			sqLiteDrv = false;
//		}
//		
//		if (sqLiteDrv == false) {
//			try {
//				screen.click(targetMySqlDriver);  
//				screen.type(Key.DOWN + Key.ENTER);
//			} catch (FindFailed e) {
//				System.out.print("Can't find any driver");
//				e.printStackTrace();
//				fail();
//			}
//		}
//		
//		/**
//		 * Database name field
//		 */
//		try {
//			Region regionDataBaseEditLabel = screen.find(targetDatabaseLabel).right(24); 
//			screen.click(regionDataBaseEditLabel);
//			
//			// Clear field
//			screen.type("a", KeyModifier.CTRL); 
//			screen.type("test_db");
//		} catch (FindFailed e) {
//			System.out.print("Can't find 'Database name'");
//			fail();
//		}		
//		
//		Region regionError = null;
//		
//		screen.click(targetOkButton);
//		
//		try {
//			regionError = screen.find(targetConnectionError);
//		} catch (FindFailed e) {
//			e.printStackTrace();
//		}
//		
//		if(regionError != null) {
//			// Accept dialog
//			screen.click(targetOkButton);
//			fail();
//		}
//	}
//	
//	@Test
//	public void testCheckSetSqLiteParametersExpectFail() throws FindFailed {				
//	    try {
//			screen.click(targetSettings);  
//		} catch (FindFailed e) {
//			System.out.print("Can't find 'Ustawienia' ");
//			fail();
//		}	    
//		
//		try {
//			screen.click(targetDBConnection);  
//		} catch (FindFailed e) {
//			System.out.print("Can't find 'Połączenie z bazą danych'");
//			fail();
//		}
//		
//		boolean sqLiteDrv = true;
//		
//		try {
//			screen.find(targetSqLiteDriver);  
//		} catch (FindFailed e) {
//			sqLiteDrv = false;
//		}
//		
//		if (sqLiteDrv == false) {
//			try {
//				screen.click(targetMySqlDriver);  
//				screen.type(Key.DOWN + Key.ENTER);
//			} catch (FindFailed e) {
//				System.out.print("Can't find any driver");
//				e.printStackTrace();
//				fail();
//			}
//		}
//		
//		/**
//		 * Database name field
//		 */
//		try {
//			Region regionDataBaseEditLabel = screen.find(targetDatabaseLabel).right(24); 
//			screen.click(regionDataBaseEditLabel);
//			screen.type("a", KeyModifier.CTRL); 
//			screen.type(Key.DELETE);
//		} catch (FindFailed e) {
//			System.out.print("Can't find 'Database name'");
//			fail();
//		}
//
//		screen.click(targetOkButton);
//		
//		Region regionError = null;
//		
//		try {
//			regionError = screen.find(targetConnectionError);
//		} catch (FindFailed e) {
//			e.printStackTrace();
//		}
//		
//		// Expect Failed error label must be in the screen
//		if(regionError == null) {
//			//
//			screen.click(targetOkButton);
//			//fail();
//		} else {
//			enterCorrectDatabase();
//		}
//		
//		screen.click(targetOkButton);
//	}
	
	@Test
	public void testCheckSetMySqlParameters() throws FindFailed	{	
	    try {
			regionServerApp.click(targetSettings);  
		} catch (FindFailed e) {
			System.out.print("Can't find 'Ustawienia' ");
			fail();
		}	    
		
		try {
			regionServerApp.click(targetDBConnection);  
		} catch (FindFailed e) {
			System.out.print("Can't find 'Połączenie z bazą danych'");
			fail();
		}
		
		boolean mySqlDrv = true;
		
		try {
			regionServerApp.find(targetMySqlDriver);  
		} catch (FindFailed e) {
			mySqlDrv = false;
		}
		
		if (mySqlDrv == false) {
			try {
				regionServerApp.click(targetSqLiteDriver);  
				regionServerApp.type(Key.DOWN + Key.ENTER);
			} catch (FindFailed e) {
				System.out.print("Can't find any driver");
				e.printStackTrace();
				fail();
			}
		}
		
		/**
		 * Database name field
		 */
		try {
			Region regionDataBaseEditLabel = regionServerApp.find(targetDatabaseLabel).right(24); 
			
			String dbNameText = regionDataBaseEditLabel.text(); 
			
			if (dbNameText != "ap") {
				try {
					regionServerApp.click(regionDataBaseEditLabel);
				} catch (FindFailed e) {
					System.out.print("Can't click to Database Edit Field");
					fail();
				}
				regionServerApp.type("a", KeyModifier.CTRL); 
				regionServerApp.type("ap");
			}
			
		} catch (FindFailed e) {
			System.out.print("Can't find 'Database name'");
			fail();
		}
		
		/**
		 * Host name field
		 */
		Region regionHostLabel = regionServerApp.find(targetUserLabel).right(20);
		String recognizeHostText = regionHostLabel.text();
			
		String correctHostNum = "127.0.0.1";
		
		if (recognizeHostText != "" && recognizeHostText != "localhost" &&
				recognizeHostText != correctHostNum) {
			regionServerApp.click(regionHostLabel);
			regionServerApp.type("a", KeyModifier.CTRL); 
			regionServerApp.type("127.0.0.1");
		}
			
		/**
		 * User name field
		 */
		Region regionUserLabel = regionServerApp.find(targetUserLabel).right(20);
		String recognizeUserText = regionUserLabel.text();
			
		String correctUser = "mmichniewski";
		
		if (recognizeUserText != correctUser) {
			regionServerApp.click(regionUserLabel);
			regionServerApp.type("a", KeyModifier.CTRL); 
			regionServerApp.type(correctUser);
		}
		
		/**
		 * Password field
		 */
		Region regionPasswordLabel = regionServerApp.find(targetPasswordLabel).right(20);
		String recognizePasswordText = regionPasswordLabel.text();
			
		String correctPassword = "Militia69";
		
		if (recognizePasswordText != correctPassword){
			regionServerApp.click(regionPasswordLabel);
			regionServerApp.type("a", KeyModifier.CTRL); 
			regionServerApp.type(correctPassword);
		}		
		
		Region regionError = null;
		
		regionServerApp.click(targetOkButton);
		
		try {
			regionError = regionServerApp.find(targetConnectionError);
		} catch (FindFailed e) {
			e.printStackTrace();
		}
		
		if(regionError != null) {
			regionServerApp.click(targetOkButton);
			fail();
		}
	}

	@Test
	public void testCheckSetMySqlWrongHostExpectFail() throws FindFailed	{	
	    try {
			regionServerApp.click(targetSettings);  
		} catch (FindFailed e) {
			System.out.print("Can't find 'Ustawienia' ");
			fail();
		}	    
		
		try {
			regionServerApp.click(targetDBConnection);  
		} catch (FindFailed e) {
			System.out.print("Can't find 'Połączenie z bazą danych'");
			fail();
		}
		
		boolean mySqlDrv = true;
		
		try {
			regionServerApp.find(targetMySqlDriver);  
		} catch (FindFailed e) {
			mySqlDrv = false;
		}
		
		if (mySqlDrv == false) {
			try {
				regionServerApp.click(targetSqLiteDriver);  
				regionServerApp.type(Key.DOWN + Key.ENTER);
			} catch (FindFailed e) {
				System.out.print("Can't find any driver");
				e.printStackTrace();
				fail();
			}
		}
		
		/**
		 * Host name field
		 */
		Region regionHostLabel = regionServerApp.find(targetHostLabel).right(24); 
		regionServerApp.click(regionHostLabel);		
		regionServerApp.type("a", KeyModifier.CTRL); 
		regionServerApp.type("wrong_host");
		
		Region regionError = null;
		
		try {
			regionError = regionServerApp.find(targetConnectionError);
		} catch (FindFailed e) {
			e.printStackTrace();
		}
		
		// Expect Failed error label must be in the screen
		if(regionError == null) {
			//
			regionServerApp.click(targetOkButton);
			//fail();
		} else {
			enterCorrectDatabase();
		}
		
		regionServerApp.click(targetOkButton);
	}
//	@Test
//	public void testa() {
//		fail("Not yet implemented");
//	}	
	
//	@Test
//	public void testb() {
//		fail("Not yet implemented");
//	}
		
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}	
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}	
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}	
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}	
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}
//	
//	@Test
//	public void test() {
//		fail("Not yet implemented");
//	}	
	
	private void enterCorrectDatabase() {
		/**
		 * Database name field
		 */
		try {
			Region regionDataBaseEditLabel = regionServerApp.find(targetDatabaseLabel).right(24); 
			regionServerApp.click(regionDataBaseEditLabel);
			regionServerApp.type("a", KeyModifier.CTRL); 
			regionServerApp.type("ap");
		} catch (FindFailed e) {
			System.out.print("Can't find 'Database name'");
		}
	}
}

//@SuppressWarnings("resource")
//Scanner userInput = new Scanner(System.in);
//System.out.print("Please enter full path to " + "\n" + "Android Photos Archive executable file" + "\n" + "PATH=");
//String path = userInput.next();
//
//Thread.sleep(100);