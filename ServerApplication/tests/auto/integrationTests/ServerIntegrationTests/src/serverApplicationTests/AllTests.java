package serverApplicationTests;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ 
	InitTest.class,
	DatabaseSettingsTests.class  })

public class AllTests {}
