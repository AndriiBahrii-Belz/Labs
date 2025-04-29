import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Profile {
    private String photo;
    private String biography;
    private List<String> interests;
    private User user;

    public Profile(String photo, String biography, User user) {
        this.photo = photo;
        this.biography = biography;
        this.interests = new ArrayList<>();
        this.user = user;
    }

    public void addInterest(String interest) {
        if (interest != null && !interest.trim().isEmpty()) {
            interests.add(interest);
        }
    }

    public void display() {
        System.out.println("Profile Information:");
        System.out.println("User: " + user.getName());
        System.out.println("Email: " + user.getEmail());
        System.out.println("Photo: " + photo);
        System.out.println("Biography: " + biography);
        System.out.println("Interests: " + (interests.isEmpty() ? "None" : String.join(", ", interests)));
    }

    public void saveToFile(BufferedWriter writer) throws IOException {
        writer.write("PROFILE:" + photo + ":" + biography + ":" + String.join(",", interests) + ":" + user.getName());
        writer.newLine();
    }

    public String getPhoto() {
        return photo;
    }

    public void setPhoto(String photo) {
        this.photo = photo;
    }

    public String getBiography() {
        return biography;
    }

    public void setBiography(String biography) {
        this.biography = biography;
    }

    public List<String> getInterests() {
        return new ArrayList<>(interests);
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }
}