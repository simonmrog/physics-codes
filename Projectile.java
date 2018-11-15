import java.text.DecimalFormat;

public class Projectile {
	
	DecimalFormat format;
	double g, initSpeed, angleDeg, angleRads, maxRange;
	
	public Projectile(double v0, double angle) {
		
		format = new DecimalFormat("0.00");
		g = 9.8;
		initSpeed = v0;
		angleDeg = angle;
		angleRads = angleDeg * Math.PI/180; //conversion of the angle
	}
	
	public void getMaximumRange() {
		
		//formula to calculate max range in a proyectile motion
		maxRange = 2 * initSpeed * initSpeed * Math.sin(angleRads) * Math.cos(angleRads)
				/ g;
		
		//formatting output
		String sRange = format.format(maxRange);
		//printing result
		System.out.println("Range of the projectile = " + sRange + " meters.");
	}
	
	public static void main(String[] args) {
		
		//Use the next two lines if you want to grab the values directly by console
		//double speed = Double.parseDouble(args[0]);
		//double angleInDegrees = Double.parseDouble(args[1]);

		Projectile P = new Projectile(12, 30);
		P.getMaximumRange();
	}
}
