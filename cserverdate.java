import java.net.*;
import java.io.*;
import java.util.*;

class serverDate
{
	public static void main(String args[]) throws Exception
	{
		ServerSocket s=new ServerSocket(7777);
		

		while(true)
		{
			System.out.println("Waiting for Connection...");
			Socket soc=s.accept();
			DataOutputStream out=new 
DataOutputStream(soc.getOutputStream());
			out.writeBytes("SERVER DATE" + (new Date ()). 
toString() + "\n");
			out.close();
			soc.close();
		}

	}
}

