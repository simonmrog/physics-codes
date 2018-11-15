import java.text.DecimalFormat;

public class Projectile {
	
	public Projectile(double speed, double angleInDegrees) {
		
		DecimalFormat format = new DecimalFormat("0.00");
		double g = 9.8, angleInRads, range;
		String sRange;

		angleInRads = angleInDegrees * Math.PI/180; //conversion of the angle
		//formula to calculate max range in a proyectile motion
		range = 2 * speed * speed * Math.sin(angleInRads) * Math.cos(angleInRads) / g;
		//formatting output
		sRange = format.format(range);
		//printing result
		System.out.println("Range of the projectile = " + sRange + " meters.");
	}
	
	public static void main(String[] args) {
		
		//Use the next two lines if you want to grab the values by console
		//double speed = Double.parseDouble(args[0]);
		//double angleInDegrees = Double.parseDouble(args[1]);

		new Projectile(12, 30);
		new Projectile(12, 45);
		new Projectile(12, 55);
	}

}
