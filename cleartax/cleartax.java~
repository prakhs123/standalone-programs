import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ClearTax {

    public static final String FILE_NAME = "input.txt";
    private static ArrayList<Integer> inputNumbers = new ArrayList<>();
    private static int bucketSize = 0;
    private static Map<Integer, Integer> bucketNumberBucketSizeMap = new HashMap<>();
    private static int lastBucketSize = -1;
    private static boolean readInputFlag = false;
    private static boolean mainLogicComputedFlag = false;

    private static void readInputFromFile() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
        try {
            String line = br.readLine();

            if (line != null) {
                String[] numbers = line.split(",");
                inputNumbers.ensureCapacity(numbers.length);
                for (int i = 0; i < numbers.length; i++) {
                    inputNumbers.add(Integer.parseInt(numbers[i].trim()));
                }
                line = br.readLine();
                bucketSize = Integer.parseInt(line);
            }
        } finally {
            br.close();
            readInputFlag = true;
        }
    }

    private static void buildHistogram() throws InputNotReadException {
        if (!readInputFlag) {
            throw new InputNotReadException("Input has not completed successfully");
        }
        for (int number : inputNumbers) {
            int bucketNumber = (number-1)/bucketSize;
            if (lastBucketSize < bucketNumber)
                lastBucketSize = bucketNumber;
            bucketNumberBucketSizeMap.compute(bucketNumber, (k, v) -> {
                if (v == null)
                    return 1;
                else
                    return v+1;
            });
        }
        mainLogicComputedFlag = true;
    }

    private static void printOutput() throws LogicNotComputedYetException {
        if (!mainLogicComputedFlag) {
            throw new LogicNotComputedYetException("Logic has not been computed yet");
        }
        for (int i = 0; i <= lastBucketSize; i++) {
            System.out.println(i*bucketSize+1 + " to " + (i+1)*bucketSize +
                    ": "+ bucketNumberBucketSizeMap.getOrDefault(i, 0));
        }
    }

    public static void main(String[] args) {
        try {
            readInputFromFile();
            buildHistogram();
            printOutput();
        } catch (IOException e) {
            System.out.println("IO ERROR");
            System.out.println(e.getMessage());
        } catch (InputNotReadException e) {
            System.out.println("INPUT NOT YET READ ERROR");
            System.out.println(e.getMessage());
        } catch (LogicNotComputedYetException e) {
            System.out.println("LOGIC NOT COMPUTED YET ERROR");
            System.out.println(e.getMessage());

        }


    }

}