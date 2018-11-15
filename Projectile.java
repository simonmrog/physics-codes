import java.text.DecimalFormat;

public class Projectile {
	
	DecimalFormat format;
	double g, initSpeed, angleDeg, angleRad;
	double timeOfFlight;
	
	public Projectile(double v0, double angle) {
		
		format = new DecimalFormat("0.00");
		g = 9.8;
		initSpeed = v0;
		angleDeg = angle;
		angleRad = angleDeg * Math.PI/180; //conversion of the angle
	}
	
	public void getMaximumRange() {
		
		//formula to calculate max range in a proyectile motion
		double maxRange = 2 * initSpeed * initSpeed * Math.sin(angleRad) * 
				Math.cos(angleRad) / g;
		
		//formatting output
		String sRange = format.format(maxRange);
		//printing result
		System.out.println("Maximum range = " + sRange + " metres.");
	}
	
	public void getTimeOfFlight() {
		
		double timeOfFlight = 2 * initSpeed * Math.sin(angleRad) / g;
		
		String sTime = format.format(timeOfFlight);
		System.out.println("Time of flight = " + sTime + " seconds.");
	}
	
	public void getMaximumHeight() {
		
		double maxHeight = initSpeed * initSpeed * Math.sin(angleRad) * Math.sin(angleRad)
				/ 2 * g;
		
		String sHeight = format.format(maxHeight);
		System.out.println("Maximum height = " + sHeight + " metres.");
		
	}
	
	public static void main(String[] args) {
		
		//Use the next two lines if you want to grab the values directly by console
		//double speed = Double.parseDouble(args[0]);
		//double angleInDegrees = Double.parseDouble(args[1]);
		
		double angle = 30, speed = 3; //in degrees and m/s
		Projectile P = new Projectile(speed, angle);
		P.getMaximumRange();
		P.getTimeOfFlight();
		P.getMaximumHeight();
	}
}
