import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.time.Duration;

/**
 * Simple example demonstrating the exact imports specified in the problem statement.
 * This example shows basic usage of Java 11+ HTTP client APIs.
 */
public class HttpClientExample {
    
    public static void main(String[] args) throws IOException, InterruptedException {
        // Create an HTTP client with custom configuration
        HttpClient client = HttpClient.newBuilder()
                .connectTimeout(Duration.ofSeconds(10))
                .build();
        
        // Build an HTTP request
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://httpbin.org/get"))
                .timeout(Duration.ofSeconds(30))
                .header("User-Agent", "Java-HTTP-Client-Example/1.0")
                .GET()
                .build();
        
        // Send the request and get the response
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        
        // Display the results
        System.out.println("Status Code: " + response.statusCode());
        System.out.println("Response Headers:");
        response.headers().map().forEach((key, value) -> 
            System.out.println("  " + key + ": " + String.join(", ", value)));
        
        System.out.println("\nResponse Body:");
        System.out.println(response.body());
    }
}