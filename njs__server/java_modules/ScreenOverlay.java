package njs__server.java_modules;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

class ScreenOverlay{

  static final Scanner scn = new Scanner( System.in );

  public static final void main( String... args ){
    System.out.println("Starting Screen Overlay");
    String line = scn.nextLine();
    while( !line.isEmpty() ){
      System.out.println( line );
      line = scn.nextLine();
    }
  }

}
