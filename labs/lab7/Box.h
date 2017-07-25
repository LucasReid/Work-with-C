#ifndef BOX_H_
#define BOX_H_
class Box{
	//data members
	private:
		double 	length;
		double 	width;
		double	height;
		
	public: 
		Box();
		virtual ~Box();
	public: 
		void 	setLength( double newLength);
		double 	getLength();
		
		void	setWidth( double newWidth);
		double	getWidth();
		
		void	setHeight( double newHeight);
		double	getHeight();
	public:
		double	getVolume();
		double	getSurfaceArea();
	public:
		void 	printMessage(double v, double sa);
};
#endif //Box
