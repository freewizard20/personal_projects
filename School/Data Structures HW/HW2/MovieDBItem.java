
/******************************************************************************
 * MovieDB의 인터페이스에서 공통으로 사용하는 클래스.
 */
public class MovieDBItem implements Comparable<MovieDBItem> {

    private final String genre;
    private final String title;

    public MovieDBItem(String genre, String title) {
        if (genre == null) throw new NullPointerException("genre");
        if (title == null) throw new NullPointerException("title");

        this.genre = genre;
        this.title = title;
    }

    public String getGenre() {
        return genre;
    }

    public String getTitle() {
        return title;
    }

    @Override
    // MovieDBItem elements compare with genre first, then title
    public int compareTo(MovieDBItem other) {
        if(this.genre.compareTo(other.genre)<0){
            return -1;
        }else if(this.genre.compareTo(other.genre)>0){
            return 1;
        }else{
            if(this.title.compareTo(other.title)<0){
                return -1;
            }else if(this.title.compareTo(other.title)>0){
                return 1;
            }else{
                return 0;
            }
        }
    }

    @Override
    public boolean equals(Object obj) {
        
    	// base case : completely same object, null or different class which are trivial
    	if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        
        // compare with genre, then title
        MovieDBItem other = (MovieDBItem) obj;
        if (genre == null) {
            if (other.genre != null)
                return false;
        } else if (!genre.equals(other.genre))
            return false;
        if (title == null) {
            if (other.title != null)
                return false;
        } else if (!title.equals(other.title))
            return false;
        
        // genre, title all same, so is equal
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((genre == null) ? 0 : genre.hashCode());
        result = prime * result + ((title == null) ? 0 : title.hashCode());
        return result;
    }

}
