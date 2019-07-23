public class PPMain {
    public static void main(String[] args) throws OutOfInkException, OutOfSpaceException {
        Paper paper = new Paper(10);
        Pen pen = new Pen(10);

        pen.write(paper, "Hello, world!");
        paper.show();
        pen.write(paper, "Hello, world!");
    }
}