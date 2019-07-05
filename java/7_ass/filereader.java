import java.io.*;
import java.nio.*;

public class filereader {

	public static void main(String[] args) 
	{
		FileInputStream fis = null;
		byte[] buffer = new byte[10];
		StringBuilder sb = new StringBuilder();
		try {
			fis = new FileInputStream("/home/ratna/Documents/java/7_ass/file.txt");

			while (fis.read(buffer) != -1) 
			{
				sb.append(new String(buffer));
				buffer = new byte[10];
			}
			fis.close();

		} catch (IOException e) 
		{
			e.printStackTrace();
		} finally 
		{
			if (fis != null)
				try {
					fis.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
		}
		String s = sb.toString();
		String[] splitStr = s.split("\\s+");
		int max = -1;
		String largest = " ";
		for (int i=0;i<splitStr.length;i++)
		{
			
			if(max<splitStr[i].length())
			{
				max = splitStr[i].length();
				largest = splitStr[i];
			}
		}
		int count = 0;
		for (int i=0;i<s.length();i++)
		{
			if(s.charAt(i)==',' || s.charAt(i)==';' || s.charAt(i)=='!' || s.charAt(i)=='.' || s.charAt(i)==':')
				count++;
		}
		int[] sum = new int[26]; 
		int[] c = new int[26];
		float[] avg = new float[26];
		char[] arr = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		char[] arr1 = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		for (int i=0;i<splitStr.length;i++)
		{
			for(int k =0; k<26;k++)
			{
			if(splitStr[i].charAt(0)==arr[k] || splitStr[i].charAt(0)==arr1[k]) 
			{
				sum[k] = sum[k] +splitStr[k].length();
				c[k]++;
			}
			} 
		}
		for(int i=0;i<26;i++)
		{
			if(c[i]!=0)
			{
			avg[i] = sum[i]/c[i];	
			System.out.println("Average length of "+arr[i]+" "+avg[i]);
			}
		}
	
		System.out.println("Largest word in the text: "+largest);
		System.out.println("Word count of the text: "+splitStr.length);
		System.out.println("Punctuation count of the text: "+count);

		String[] splitStr2 = s.split("\\.");
		for (int i=0;i<splitStr2.length;i++)
		{
			for(int j=0;j<splitStr2[i].length();j++)
			{					
				if(Character.isDigit(splitStr2[i].charAt(j)))
				{	System.out.println(splitStr2[i]);
					break;
				}
			}
		}



	}

}

