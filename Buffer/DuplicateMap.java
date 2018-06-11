import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

// Copy from https://code.i-harness.com/ko/q/197afd
// 같은 name을 가진 station을 관리하기 위하여(환승 역) DuplicateMap을 사용한다.
public class DuplicateMap<K, V> {
	private Map<K, ArrayList<V>> m = new HashMap<>();

    public void put(K k, V v) {
        if (m.containsKey(k)) {
            m.get(k).add(v);
        } else {
            ArrayList<V> arr = new ArrayList<>();
            arr.add(v);
            m.put(k, arr);
        }
    }

    public ArrayList<V> get(K k) {
        return m.get(k);
    }

    public V get(K k, int index) {
        return m.get(k).size()-1 < index ? null : m.get(k).get(index);
    }
    
    public Set<K> keySet(){
    	return m.keySet();
    }
}
