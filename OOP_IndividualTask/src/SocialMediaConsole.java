import java.io.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SocialMediaConsole {
    private List<User> users;
    private List<Profile> profiles;
    private List<Post> posts;
    private User currentUser;
    private Scanner scanner;

    public SocialMediaConsole() {
        users = new ArrayList<>();
        profiles = new ArrayList<>();
        posts = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public void run() {
        while (true) {
            System.out.println("\nSocial Media Console");
            System.out.println("1. Create User and Profile");
            System.out.println("2. Select User");
            System.out.println("3. Add Interest");
            System.out.println("4. Create Post");
            System.out.println("5. Display Profile and Posts");
            System.out.println("6. Save to File");
            System.out.println("7. Load from File");
            System.out.println("8. Exit");
            System.out.print("Choose an option: ");

            int choice;
            try {
                choice = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a number.");
                continue;
            }

            switch (choice) {
                case 1:
                    createUserAndProfile();
                    break;
                case 2:
                    selectUser();
                    break;
                case 3:
                    addInterest();
                    break;
                case 4:
                    createPost();
                    break;
                case 5:
                    displayAll();
                    break;
                case 6:
                    saveToFile();
                    break;
                case 7:
                    loadFromFile();
                    break;
                case 8:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }

    private void createUserAndProfile() {
        System.out.print("Enter name: ");
        String name = scanner.nextLine().trim();
        System.out.print("Enter email: ");
        String email = scanner.nextLine().trim();
        System.out.print("Enter photo URL: ");
        String photo = scanner.nextLine().trim();
        System.out.print("Enter biography: ");
        String biography = scanner.nextLine().trim();

        if (name.isEmpty() || email.isEmpty()) {
            System.out.println("Name and email are required!");
            return;
        }

        if (users.stream().anyMatch(u -> u.getName().equalsIgnoreCase(name))) {
            System.out.println("User with this name already exists!");
            return;
        }

        User user = new User(name, email);
        users.add(user);
        profiles.add(new Profile(photo, biography, user));
        System.out.println("User and Profile created successfully!");
    }

    private void selectUser() {
        if (users.isEmpty()) {
            System.out.println("No users available!");
            return;
        }

        System.out.println("Available users:");
        for (int i = 0; i < users.size(); i++) {
            System.out.println((i + 1) + ". " + users.get(i).getName());
        }
        System.out.print("Enter user number (1-" + users.size() + "): ");

        int userIndex;
        try {
            userIndex = Integer.parseInt(scanner.nextLine()) - 1;
            if (userIndex < 0 || userIndex >= users.size()) {
                System.out.println("Invalid user number!");
                return;
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a number!");
            return;
        }

        currentUser = users.get(userIndex);
        System.out.println("Selected user: " + currentUser.getName());
    }

    private void addInterest() {
        if (currentUser == null) {
            System.out.println("Select a user first!");
            return;
        }

        Profile profile = profiles.stream()
                .filter(p -> p.getUser().getName().equals(currentUser.getName()))
                .findFirst()
                .orElse(null);

        if (profile == null) {
            System.out.println("No profile found for selected user!");
            return;
        }

        System.out.print("Enter interest: ");
        String interest = scanner.nextLine().trim();
        if (!interest.isEmpty()) {
            profile.addInterest(interest);
            System.out.println("Interest added!");
        } else {
            System.out.println("Interest cannot be empty!");
        }
    }

    private void createPost() {
        if (currentUser == null) {
            System.out.println("Select a user first!");
            return;
        }

        System.out.print("Enter post content: ");
        String content = scanner.nextLine().trim();
        if (!content.isEmpty()) {
            posts.add(new Post(content, currentUser, LocalDate.now()));
            System.out.println("Post created!");
        } else {
            System.out.println("Post content cannot be empty!");
        }
    }

    private void displayAll() {
        if (currentUser == null) {
            System.out.println("Select a user first!");
            return;
        }

        Profile profile = profiles.stream()
                .filter(p -> p.getUser().getName().equals(currentUser.getName()))
                .findFirst()
                .orElse(null);

        if (profile == null) {
            System.out.println("No profile found for selected user!");
            return;
        }

        profile.display();

        List<Post> userPosts = posts.stream()
                .filter(p -> p.getAuthor().getName().equals(currentUser.getName()))
                .toList();

        if (userPosts.isEmpty()) {
            System.out.println("\nNo posts for this user!");
        } else {
            System.out.println("\nPosts:");
            for (Post post : userPosts) {
                post.display();
                System.out.println();
            }
        }
    }

    private void saveToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\Users\\andri\\Desktop\\University\\ООП2\\KR_2.txt"))) {
            for (User user : users) {
                user.saveToFile(writer);
            }
            for (Profile profile : profiles) {
                profile.saveToFile(writer);
            }
            for (Post post : posts) {
                post.saveToFile(writer);
            }
            System.out.println("Data saved successfully!");
        } catch (IOException e) {
            System.out.println("Error saving data: " + e.getMessage());
        }
    }

    private void loadFromFile() {
        users.clear();
        profiles.clear();
        posts.clear();
        currentUser = null;

        try (BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\andri\\Desktop\\University\\ООП2\\KR_2.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(":", -1);
                if (parts[0].equals("USER") && parts.length >= 3) {
                    users.add(new User(parts[1], parts[2]));
                } else if (parts[0].equals("PROFILE") && parts.length >= 5) {
                    User user = users.stream()
                            .filter(u -> u.getName().equals(parts[4]))
                            .findFirst()
                            .orElse(null);
                    if (user != null) {
                        Profile profile = new Profile(parts[1], parts[2], user);
                        if (!parts[3].isEmpty()) {
                            for (String interest : parts[3].split(",")) {
                                profile.addInterest(interest);
                            }
                        }
                        profiles.add(profile);
                    }
                } else if (parts[0].equals("POST") && parts.length >= 4) {
                    User author = users.stream()
                            .filter(u -> u.getName().equals(parts[2]))
                            .findFirst()
                            .orElse(null);
                    if (author != null) {
                        posts.add(new Post(parts[1], author, LocalDate.parse(parts[3])));
                    }
                }
            }
            System.out.println("Data loaded successfully!");
        } catch (IOException e) {
            System.out.println("Error loading data: " + e.getMessage());
        }
    }
}