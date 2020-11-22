# include <iostream>

using namespace std;
int split(int *data, int min, int max){
	    int left, right, splitPoint, splitVal, temp;
	        left = min + 1;
			right = max;
				splitVal = data[min];

					while(left <= right){
								while(data[left]<=splitVal && left<=right){
												left += 1;
														}			
										while(data[right]>=splitVal && left<=right){
														right -= 1;
																}
												if(left < right){
																temp = data[left];
																			data[left] = data[right];
																						data[right] = temp;
																								}
													}
						splitPoint = right;
							temp = data[min];
								data[min] = data[splitPoint];
									data[splitPoint] = temp;
									    
										return splitPoint;
}
void quicksort(int *data, int min, int max){
	    if(min < max){
		            int splitPoint = split(data, min, max);
			            quicksort(data, min, splitPoint - 1);
				            quicksort(data, splitPoint + 1, max);
					        }
}
int main(){
	    int N;
	        cin >> N;
		    int data[N];
		        for(int i = 0; i < N; i += 1){
				        cin >> data[i];
					    }
			    quicksort(data, 0, N-1);
			        for(int i = 0; i < N; i += 1){
					        cout << data[i] << endl;
						    }
				    return 0;
}

