import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;


class HW2 {

	public static void main(String[] args) {
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
		int n = 0, super1 = 0, super2 = 0, super3 = 0;
		LinkedList<Integer> people = null;
		try {
			n = Integer.parseInt(bi.readLine());
			n -= 3;
			super1 = Integer.parseInt(bi.readLine());
			super2 = Integer.parseInt(bi.readLine());
			super3 = Integer.parseInt(bi.readLine());
			
			people = new LinkedList<Integer>();
			for(int i = 0; i < n; i++){
				people.add(Integer.parseInt(bi.readLine()));
			}
		} catch (IOException e) {}
		
		int treshold = Math.max(Math.max(super1, super2), super3) + Math.min(Math.min(super1, super2), super3);
		Collections.sort(people);
		
		int tripleCount = 0;
		while(true){
			if(people.isEmpty()){
				break;	// all people are in teams
			}
			
			int strong = people.getLast();
			Iterator<Integer> itWeak = people.iterator();
			boolean deleteItems = false;
			
			Iterator<Integer> itBound = people.iterator();
			itBound.next(); itBound.next();
			for(; itBound.hasNext(); itBound.next()){
				int weak = itWeak.next();
				if(strong + weak > treshold){
					deleteItems = true;
					break;
				}
			}
			
			if(deleteItems){
				itWeak.remove();		// weak
				itWeak.next();
				itWeak.remove();		// middle
				people.removeLast();	// strong
				
				tripleCount++;				
			}
			else{
				break;	// no other team is strong enough
			}
			
		}
		
		System.out.println(tripleCount);
	}
}
