#ifndef CORE_CONSTANTS_H
#define CORE_CONSTANTS_H

/* A collection of frequently used mathematical constants. */
namespace MathConstants{
	// The Wallis Constant 
	const double WallisConstant 		= 2.09455148154232659148;

	// Sierpiński's constant
	const double SierpinskiConstant 	= 2.58498175957925321706;

	const double MagicAngle 			= 0.955316618124509278163;

	const double ChebyshevConstant 		= 0.59017029950804811302;

	// The number E
	const double E 						= 2.7182818284590452353602874713526624977572470937000;
	
	// The number log[2](e)
	const double Log2E					= 1.4426950408889634073599246810018921374266459541530;
	
	// The number log[10](e)
	const double Log10E 				= 0.43429448190325182765112891891660508229439700580366;
	
	// The number log[e](2)
	const double Ln2 					= 0.69314718055994530941723212145817656807550013436026;
	
	// The number log[e](10)
	const double Ln10 					= 2.3025850929940456840179914546843642076011014886288;
	
	// The number log[e](pi)
	const double LnPi 					= 1.1447298858494001741434273513530587116472948129153;
	
	// The number log[e](2*pi)/2
	const double Ln2PiOver2 			= 0.91893853320467274178032973640561763986139747363780;
	
	// The number 1/e
	const double InvE					= 0.36787944117144232159552377016146086744581113103176;
	
	// The number sqrt(e)
	const double SqrtE 					= 1.6487212707001281468486507878141635716537761007101;
	
	// The number sqrt(2)
	const double Sqrt2 					= 1.4142135623730950488016887242096980785696718753769;
	
	// The number sqrt(3)
	const double Sqrt3 					= 1.7320508075688772935274463415058723669428052538104;
	
	// The number sqrt(1/2) = 1/sqrt(2) = sqrt(2)/2
	const double Sqrt1Over2 			= 0.70710678118654752440084436210484903928483593768845;
	
	// The number sqrt(3)/2
	const double HalfSqrt3 				= 0.86602540378443864676372317075293618347140262690520;
	
	// The number pi
	const double Pi 					= 3.1415926535897932384626433832795028841971693993751;
	
	// The number pi*2
	const double Pi2 					= 6.2831853071795864769252867665590057683943387987502;
	
	// The number pi/2
	const double PiOver2 				= 1.5707963267948966192313216916397514420985846996876;
	
	// The number pi*3/2
	const double Pi3Over2 				= 4.71238898038468985769396507491925432629575409906266;
	
	// The number pi/4
	const double PiOver4 				= 0.78539816339744830961566084581987572104929234984378;
	
	// The number sqrt(pi)
	const double SqrtPi 				= 1.7724538509055160272981674833411451827975494561224;
	
	// The number sqrt(2pi)
	const double Sqrt2Pi 				= 2.5066282746310005024157652848110452530069867406099;
	
	// The number sqrt(pi/2)
	const double SqrtPiOver2 			= 1.2533141373155002512078826424055226265034933703050;
	
	// The number sqrt(2*pi*e)
	const double Sqrt2PiE 				= 4.1327313541224929384693918842998526494455219169913;
	
	// The number log(sqrt(2*pi))
	const double LogSqrt2Pi 			= 0.91893853320467274178032973640561763986139747363778;
	
	// The number log(sqrt(2*pi*e))
	const double LogSqrt2PiE 			= 1.4189385332046727417803297364056176398613974736378;
	
	// The number log(2 * sqrt(e / pi))
	const double LogTwoSqrtEOverPi 		= 0.620782237635245222345518445781647212251852727902597;
	
	// The number 1/pi
	const double InvPi 					= 0.31830988618379067153776752674502872406891929148091;
	
	// The number 2/pi
	const double TwoInvPi 				= 0.63661977236758134307553505349005744813783858296182;
	
	// The number 1/sqrt(pi)
	const double InvSqrtPi 				= 0.56418958354775628694807945156077258584405062932899;
	
	// The number 1/sqrt(2pi)
	const double InvSqrt2Pi 			= 0.39894228040143267793994605993438186847585863116492;
	
	// The number 2/sqrt(pi)
	const double TwoInvSqrtPi 			= 1.1283791670955125738961589031215451716881012586580;
	
	// The number 2 * sqrt(e / pi)
	const double TwoSqrtEOverPi 		= 1.8603827342052657173362492472666631120594218414085755;

	// The number (pi)/180 - factor to convert from Degree (deg) to Radians (rad).
	const double Degree 				= 0.017453292519943295769236907684886127134428718885417;
	
	// The number (pi)/200 - factor to convert from NewGrad (grad) to Radians (rad).
	const double Grad 					= 0.015707963267948966192313216916397514420985846996876;
	
	// The number ln(10)/20 - factor to convert from Power Decibel (dB) to Neper (Np).
	const double PowerDecibel 			= 0.11512925464970228420089957273421821038005507443144;
	
	// The number ln(10)/10 - factor to convert from Neutral Decibel (dB) to Neper (Np).
	const double NeutralDecibel 		= 0.23025850929940456840179914546843642076011014886288;

	/* 
	The Catalan constant. 
	Sum(k=0 -> inf){ (-1)^k/(2*k + 1)2 } 
	*/
	const double Catalan 				= 0.9159655941772190150546035149323841107741493742816721342664981196217630197762547694794;
	
	/* 
	The Euler-Mascheroni constant
	lim(n -> inf){ Sum(k=1 -> n) { 1/k - log(n) } }
	*/
	const double EulerMascheroni 		= 0.5772156649015328606065120900824024310421593359399235988057672348849;
	
	// The number (1+sqrt(5))/2, also known as the golden ratio
	const double GoldenRatio 			= 1.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072;
	
	/* 
	The Glaisher constant
	e^(1/12 - Zeta(-1))
	*/
	const double Glaisher 				= 1.2824271291006226368753425688697917277676889273250011920637400217404063088588264611297;
	
	/* 
	The Khinchin constant
	prod(k=1 -> inf){1+1/(k*(k+2))^log(k,2)}
	*/
	const double Khinchin 				= 2.6854520010653064453097148354817956938203822939944629530511523455572188595371520028011;

	// The size of a double in bytes.
	const int SizeOfDouble 				= sizeof(double);
	
	// The size of an int in bytes.
	const int SizeOfInt 				= sizeof(int);
	
	// The size of a float in bytes.
	const int SizeOfFloat 				= sizeof(float);
	
	// The size of a Complex in bytes.
	const int SizeOfComplex 			= 2 * SizeOfDouble;
	
	// The size of a Complex in bytes.
	const int SizeOfComplex32 			= 2 * SizeOfFloat;

}

// Universal Constants
namespace UniversalConstants{
	
	
	/* Speed of Light in Vacuum: 
	c_0 = 2.99792458e8 [m s^-1] 
	(defined, exact; 2007 CODATA) */
	const double SpeedOfLight 			= 2.99792458e8;
	
	/* Magnetic Permeability in Vacuum: 
	mu_0 = 4*Pi * 10^-7 [N A^-2 = kg m A^-2 s^-2] 
	(defined, exact; 2007 CODATA) */
	const double MagneticPermeability 	= 1.2566370614359172953850573533118011536788677597500e-6;
	
	/* Electric Permittivity in Vacuum: 
	epsilon_0 = 1/(mu_0*c_0^2) [F m^-1 = A^2 s^4 kg^-1 m^-3] 
	(defined, exact; 2007 CODATA) */
	const double ElectricPermittivity   = 8.8541878171937079244693661186959426889222899381429e-12;
	
	/* Characteristic Impedance of Vacuum: 
	Z_0 = mu_0*c_0 [Ohm = m^2 kg s^-3 A^-2] 
	(defined, exact; 2007 CODATA) */
	const double CharacteristicImpedanceVacuum = 376.73031346177065546819840042031930826862350835242;

	/* Newtonian Constant of Gravitation: 
	G = 6.67429e-11 [m^3 kg^-1 s^-2] 
	(2007 CODATA) */
	const double GravitationalConstant 	= 6.67429e-11;
	
	/* Planck's constant: 
	h = 6.62606896e-34 [J s = m^2 kg s^-1] 
	(2007 CODATA) */
	const double PlancksConstant 		= 6.62606896e-34;

	/* Reduced Planck's constant: 
	h_bar = h / (2*Pi) [J s = m^2 kg s^-1] 
	(2007 CODATA) */
	const double DiracsConstant 		= 1.054571629e-34;

	/* Planck mass: 
	m_p = (h_bar*c_0/G)^(1/2) [kg] 
	(2007 CODATA) */
	const double PlancksMass 			= 2.17644e-8;

	/* Planck temperature: 
	T_p = (h_bar*c_0^5/G)^(1/2)/k [K] 
	(2007 CODATA) */
	const double PlancksTemperature 	= 1.416786e32;

	/* Planck length: 
	l_p = h_bar/(m_p*c_0) [m] 
	(2007 CODATA) */
	const double PlancksLength 			= 1.616253e-35;

	/* Planck time: 
	t_p = l_p/c_0 [s] 
	(2007 CODATA) */
	const double PlancksTime 			= 5.39124e-44;
}

namespace ElectroMagConstants {
	/* Elementary Electron Charge: 
	e = 1.602176487e-19 [C = A s] 
	(2007 CODATA) */
	const double ElementaryCharge 		= 1.602176487e-19;
	
	/* Magnetic Flux Quantum: 
	theta_0 = h/(2*e) [Wb = m^2 kg s^-2 A^-1] 
	(2007 CODATA) */
	const double MagneticFluxQuantum 	= 2.067833668e-15;
	
	/* Conductance Quantum: 
	G_0 = 2*e^2/h [S = m^-2 kg^-1 s^3 A^2] 
	(2007 CODATA) */
	const double ConductanceQuantum 	= 7.7480917005e-5;
	
	/* Josephson Constant: 
	K_J = 2*e/h [Hz V^-1] 
	(2007 CODATA) */
	const double JosephsonConstant 		= 483597.891e9;
	
	/* Von Klitzing Constant: 
	R_K = h/e^2 [Ohm = m^2 kg s^-3 A^-2] 
	(2007 CODATA) */
	const double VonKlitzingConstant 	= 25812.807557;
	
	/* Bohr Magneton: 
	mu_B = e*h_bar/2*m_e [J T^-1] 
	(2007 CODATA) */
	const double BohrMagneton 			= 927.400915e-26;
	
	/* Nuclear Magneton: 
	mu_N = e*h_bar/2*m_p [J T^-1] 
	(2007 CODATA) */
	const double NuclearMagneton 		= 5.05078324e-27;
}

/* 
Scientific Prefixes

*/
namespace Prefix {
	
	// The SI prefix factor corresponding to 1,000,000,000,000,000,000,000,000
	const double Yotta 	= 1e24;
	
	// The SI prefix factor corresponding to 1,000,000,000,000,000,000,000
	const double Zetta 	= 1e21;
	
	// The SI prefix factor corresponding to 1,000,000,000,000,000,000
	const double Exa 	= 1e18;
	
	// The SI prefix factor corresponding to 1,000,000,000,000,000
	const double Peta 	= 1e15;
	
	// The SI prefix factor corresponding to 1,000,000,000,000
	const double Tera 	= 1e12;
	
	// The SI prefix factor corresponding to 1,000,000,000
	const double Giga 	= 1e9;
	
	// The SI prefix factor corresponding to 1,000,000
	const double Mega 	= 1e6;
	
	// The SI prefix factor corresponding to 1000
	const double Kilo 	= 1e3;
	
	// The SI prefix factor corresponding to 100
	const double Hecto 	= 1e2;
	
	// The SI prefix factor corresponding to 10
	const double Deca 	= 1e1;
	
	// The SI prefix factor corresponding to 0.1
	const double Deci 	= 1e-1;
	
	// The SI prefix factor corresponding to 0.01
	const double Centi 	= 1e-2;
	
	// The SI prefix factor corresponding to 0.001
	const double Milli 	= 1e-3;
	
	// The SI prefix factor corresponding to 0.000,001
	const double Micro 	= 1e-6;
	
	// The SI prefix factor corresponding to 0.000,000,001
	const double Nano 	= 1e-9;
	
	// The SI prefix factor corresponding to 0.000,000,000,001
	const double Pico 	= 1e-12;
	
	// The SI prefix factor corresponding to 0.000,000,000,000,001
	const double Femto 	= 1e-15;
	
	// The SI prefix factor corresponding to 0.000,000,000,000,000,001
	const double Atto 	= 1e-18;
	
	// The SI prefix factor corresponding to 0.000,000,000,000,000,000,001
	const double Zepto 	= 1e-21;
	
	// The SI prefix factor corresponding to 0.000,000,000,000,000,000,000,001
	const double Yocto 	= 1e-24;
}

#endif