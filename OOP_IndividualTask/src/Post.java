import java.io.BufferedWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Post {
    private String content;
    private User author;
    private LocalDate creationDate;

    public Post(String content, User author, LocalDate creationDate) {
        this.content = content;
        this.author = author;
        this.creationDate = creationDate;
    }

    public long daysSincePost() {
        return ChronoUnit.DAYS.between(creationDate, LocalDate.now());
    }

    public void display() {
        System.out.println("Post Information:");
        System.out.println("Author: " + author.getName());
        System.out.println("Content: " + content);
        System.out.println("Created: " + creationDate);
        System.out.println("Days since post: " + daysSincePost());
    }

    public void saveToFile(BufferedWriter writer) throws IOException {
        writer.write("POST:" + content + ":" + author.getName() + ":" + creationDate);
        writer.newLine();
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public User getAuthor() {
        return author;
    }

    public void setAuthor(User author) {
        this.author = author;
    }

    public LocalDate getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(LocalDate creationDate) {
        this.creationDate = creationDate;
    }
}