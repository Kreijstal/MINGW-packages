# Java HTTP Client for MINGW-packages

This package provides Java HTTP client utilities that demonstrate the usage of Java 11+ HTTP client APIs.

## Quick Start

1. **Install the package** (when integrated into MINGW-packages):
   ```bash
   pacman -S mingw-w64-x86_64-java-http-client
   ```

2. **Build the utility**:
   ```bash
   cd $MINGW_PREFIX/share/java-http-client
   ./build.sh
   ```

3. **Run HTTP requests**:
   ```bash
   # GET request
   java -jar java-http-client.jar https://httpbin.org/get
   
   # POST with JSON
   java -jar java-http-client.jar https://httpbin.org/post POST '{"test": "data"}'
   ```

## Files Included

- `src/HttpClientUtil.java` - Full HTTP client utility
- `HttpClientExample.java` - Simple usage example
- `build.sh` - Compilation script
- `README.md` - Detailed documentation

## Java Imports Demonstrated

All the required Java HTTP client imports are properly utilized:

```java
import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.time.Duration;
```

This package provides a complete reference implementation for Java HTTP client functionality in the MINGW environment.