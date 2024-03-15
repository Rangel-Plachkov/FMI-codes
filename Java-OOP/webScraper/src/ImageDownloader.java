import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.*;
import java.net.URL;
import java.util.HashSet;
import java.util.Set;

public class ImageDownloader {
    public static void main(String[] args) {
        String siteUrl = "https://syndamia.com/about/";
        downloadImages(siteUrl);
    }

    private static void downloadImages(String siteUrl) {
        try {
            Document document = Jsoup.connect(siteUrl).get();

            // Extract image URLs from the HTML
            Elements imgElements = document.select("img[src]");
            Set<String> imageUrls = new HashSet<>();

            for (Element imgElement : imgElements) {
                String imgUrl = imgElement.absUrl("src");
                if (!imgUrl.isEmpty()) {
                    imageUrls.add(imgUrl);
                }
            }

            // Download each image
            for (String imageUrl : imageUrls) {
                downloadImage(imageUrl);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void downloadImage(String imageUrl) {
        try {
            URL url = new URL(imageUrl);
            InputStream in = new BufferedInputStream(url.openStream());
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = in.read(buffer, 0, 1024)) != -1) {
                out.write(buffer, 0, bytesRead);
            }

            // Save the image to a file (you can customize the file name)
            String fileName = imageUrl.substring(imageUrl.lastIndexOf("/") + 1);
            try (FileOutputStream fos = new FileOutputStream(fileName)) {
                fos.write(out.toByteArray());
            }

            System.out.println("Downloaded: " + imageUrl);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


/*
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;

public class SimpleWebScraper {

    public static void main(String[] args) {
        String websiteUrl = "https://www.facebook.com/";

        try {
            // Construct the URL for the robots.txt file
            String robotsTxtUrl = websiteUrl + "/robots.txt";

            // Connect to the robots.txt URL and get the document
            Document document = Jsoup.connect(robotsTxtUrl).get();

            // Print the contents of the robots.txt file
            System.out.println("Robots.txt content:\n" + document.text());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
*/
    /*
    public static void main(String[] args) {

        String url = "https://www.wikipedia.org/";

        try {
            // Connect to the website and get the HTML document
            Document document = Jsoup.connect(url).get();

            // Extract and print the title of the website
            String title = document.title();
            System.out.println("Title: " + title);

            // Extract and print all the links on the page
            Elements links = document.select("a[href]");
            System.out.println("\nLinks:");
            for (Element link : links) {
                System.out.println(link.attr("href"));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }}

     */
