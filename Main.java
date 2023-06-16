import com.itextpdf.text.Document;
import com.itextpdf.text.Element;
import com.itextpdf.text.Font;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;
import com.itextpdf.text.pdf.draw.LineSeparator;
import com.itextpdf.text.Image;
import com.itextpdf.text.Anchor;
import java.lang.*;
import java.awt.Desktop;
import java.util.*;
import java.io.*;
import java.text.DecimalFormat;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import com.itextpdf.text.Chunk;

public class Main {
    private static final Pattern EMAIL_PATTERN = Pattern.compile(
            "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"
                    + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String in = "";
        int f, t;
        try {
            Document resume = new Document(); // ! Crate a new Document
            Font font = new Font(Font.FontFamily.TIMES_ROMAN, 24, Font.BOLD); // ! setting font
            PdfWriter.getInstance(resume, new FileOutputStream("resume.pdf")); // ! Creating a new PDF doc
            resume.open();
            // -----------------------------------------Name-----------
            System.out.print("Enter First Name : "); // ! Name Input
            String fname = cin.nextLine();
            System.out.print("Enter Last Name : ");
            String lname = cin.nextLine();
            fname += "  " + lname;
            Paragraph headingPara = new Paragraph(fname, font);
            headingPara.setAlignment(Element.ALIGN_CENTER);
            resume.add(headingPara);
            // -----------------------------------------------CareerObjective------
            Paragraph ch = new Paragraph("\nCareer Objective", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
            ch.setAlignment(Element.ALIGN_LEFT);
            resume.add(ch);// ! Career Objective heading
            System.out.print("Enter Career Objective : ");
            in = cin.nextLine();
            Paragraph crobj = new Paragraph("        " + in + "\n", new Font(Font.FontFamily.TIMES_ROMAN, 10));
            crobj.setAlignment(Element.ALIGN_LEFT); // ! career Objective
            resume.add(crobj);
            // ! New Line
            LineSeparator lineSeparator = new LineSeparator();
            lineSeparator.setLineWidth(1); // Set the line width
            lineSeparator.setPercentage(100); // Set the width percentage of the line
            resume.add(new Paragraph("\n")); // Add some space before the line separator
            resume.add(lineSeparator);
            // -----------------------------------Research---------
            System.out.println("Are You doing any Research ?\nEnter 1 if yes , else 0 : ");
            int n = cin.nextInt();
            String research = "";
            if (n == 1) {
                System.out.printf("Enter Your Research Title : ");
                research += cin.nextLine();
                if (research.length() == 0) {
                    research = cin.nextLine();
                }
                ch = new Paragraph("Research", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                crobj = new Paragraph("        " + research + "\n", new Font(Font.FontFamily.TIMES_ROMAN, 10));
                crobj.setAlignment(Element.ALIGN_LEFT); // ! career Objective
                resume.add(crobj);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // --------------------------------Technology and Skills-------------
            ch = new Paragraph("Technology and Skills", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
            ch.setAlignment(Element.ALIGN_LEFT);
            resume.add(ch);
            System.out.println("Now Comes the section where you show case your skill");
            while (true) {
                System.out.print("Enter 1 to add a skill else 0 :");
                n = cin.nextInt();
                String a = "";
                if (n == 1) {
                    System.out.print("Enter skill : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(
                            new Paragraph("        " + "\u2022" + "  " + a,
                                    new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                } else
                    break;
            }
            resume.add(new Paragraph("\n")); // Add some space before the line separator
            resume.add(lineSeparator);
            // -----------------------------Acadamic Projects-------------
            ch = new Paragraph("Projects", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
            ch.setAlignment(Element.ALIGN_LEFT);
            resume.add(ch);
            String a = "";
            System.out.println("Now Comes the section how you have applied your skill");
            System.out.print("Have you done any projects ?\n Enter 1 if yes else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                do {
                    System.out.print("Enter Title of the project : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    ch = new Paragraph("        " + "\u2022" + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 12, Font.BOLD));
                    ch.setAlignment(Element.ALIGN_LEFT);
                    resume.add(ch);
                    a = "";
                    System.out.print("Describe about Your Project : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(
                            new Paragraph("            " + a,
                                    new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.print("Enter project Link : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    Anchor anchor = new Anchor("Project Link", new Font(Font.FontFamily.TIMES_ROMAN, 10));
                    anchor.setReference(a);
                    Paragraph paragraph = new Paragraph();
                    paragraph.add(anchor);
                    paragraph.setAlignment(Element.ALIGN_RIGHT);
                    resume.add(paragraph);
                    resume.add(new Paragraph("\n"));
                    System.out.print("Enter 1 to add a Project else 0 :");
                    n = cin.nextInt();
                    if (n == 0)
                        break;
                } while (true);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // ------------------------------------------Education----------------------------------------
            System.out.print("Do you have any Education ?\nEnter 1 if yes , else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                ch = new Paragraph("Education", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                Vector<String> edu = new Vector<String>();
                edu.add("Graduation");
                edu.add("Intermediate / +2");
                edu.add("Schooling / 10th standard");
                edu.add("Others");
                edu.add("Exit");
                do {
                    for (int i = 0; i < edu.size(); i++) {
                        System.out.println((i + 1) + " . " + edu.get(i));
                    }
                    System.out.print("Enter Your Education : ");
                    n = cin.nextInt();
                    while (n > edu.size() || n < 1) {
                        System.out.println("Invalid Input , Enter Again : ");
                        n = cin.nextInt();
                    }
                    if (n == edu.size())
                        break;
                    else if (edu.get(n - 1) == "Others") {
                        System.out.print("Enter education type : ");
                        a = cin.nextLine();
                        if (a.length() == 0) {
                            a = cin.nextLine();
                        }
                    } else {
                        a = edu.get(n - 1);
                        edu.remove(n - 1);
                    }
                    ch = new Paragraph("        " + "\u2022" + " " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 12, Font.BOLD));
                    ch.setAlignment(Element.ALIGN_LEFT);
                    resume.add(ch);
                    System.out.print("Enter Instituation name : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(new Paragraph("            " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.print("Enter Location : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(new Paragraph("            " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    a = "";
                    System.out.println("Enter evaluation");
                    System.out.println("1 . CGPA");
                    System.out.println("2 . Marks");
                    System.out.println("3 . Still Not Yet Completed one Semester");
                    n = cin.nextInt();
                    while (n > 2 || n < 1) {
                        System.out.println("Invalid Input , Enter Again : ");
                        n = cin.nextInt();
                    }
                    if (n == 1) {
                        System.out.print("Enter CGPA : ");
                        float m = cin.nextFloat();
                        a = "CGPA : " + Float.toString(m);
                        resume.add(new Paragraph("            " + a,
                                new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    } else if (n == 2) {
                        System.out.print("Enter aquired marks : ");
                        int m = cin.nextInt();
                        System.out.print("Enter Total marks : ");
                        n = cin.nextInt();
                        m = (n / m) * 100;
                        DecimalFormat decimalFormat = new DecimalFormat("#.##");
                        String roundedNumber = decimalFormat.format(m);
                        a = "Percentage : " + roundedNumber + "%";
                        resume.add(new Paragraph("            " + a,
                                new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    }
                    resume.add(new Paragraph("            " + n + " years",
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    while (true) {
                        System.out.print("Enter From : ");
                        f = cin.nextInt();
                        System.out.print("Enter To : ");
                        t = cin.nextInt();
                        if (f <= t) {
                            break;
                        } else
                            System.out.println("Incorrect format ReEnter");
                    }
                    a = Integer.toString(f) + "-" + Integer.toString(t);
                    resume.add(new Paragraph("            " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));

                } while (true);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // ----------------------Work Experience--------------------
            System.out.println("Do you have any work Experience ?\nEnter 1 if yes , else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                ch = new Paragraph("Work Experience", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                do {
                    System.out.print("Enter Organization worked : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    ch = new Paragraph("        " + "\u2022" + " " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 12, Font.BOLD));
                    ch.setAlignment(Element.ALIGN_LEFT);
                    resume.add(ch);
                    System.out.println("1 . Part time");
                    System.out.println("2 . Internship");
                    System.out.println("3 . Full time Job");
                    System.out.print("Enter Your Work Type : ");
                    n = cin.nextInt();
                    if (n == 1)
                        a = "Part time";
                    else if (n == 2)
                        a = "Internship";
                    else
                        a = "Full time Job";
                    ch = new Paragraph("          " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10));
                    resume.add(ch);
                    System.out.println("Enter work Duration");
                    while (true) {
                        System.out.print("Enter From : ");
                        f = cin.nextInt();
                        System.out.print("Enter To : ");
                        t = cin.nextInt();
                        if (f <= t) {
                            break;
                        } else
                            System.out.println("Incorrect format ReEnter");
                    }
                    a = Integer.toString(f) + "-" + Integer.toString(t);
                    resume.add(new Paragraph("            " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    resume.add(new Paragraph("          " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.println("Enter job Discription : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(new Paragraph("          " + a,
                            new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.print("Enter 1 to add a Work Experience else 0 :");
                    n = cin.nextInt();
                    if (n == 0)
                        break;
                } while (true);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // -------------------------------Certifications----------------------------------------------
            System.out.println("Do you Have Any Certifications ?\nEnter 1 if yes , else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                ch = new Paragraph("Certifications", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                do {
                    System.out.print("Enter Certification Name : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    System.out.print("Enter Learning Platform : ");
                    String b = cin.nextLine();
                    if (b.length() == 0) {
                        b = cin.nextLine();
                    }
                    a += " - " + b;
                    while (true) {
                        System.out.print("Enter From : ");
                        f = cin.nextInt();
                        System.out.print("Enter To : ");
                        t = cin.nextInt();
                        if (f <= t) {
                            break;
                        } else
                            System.out.println("Incorrect format ReEnter");
                    }
                    a = "        " + Integer.toString(f) + "-" + Integer.toString(t);
                    resume.add(
                            new Paragraph("        " + "\u2022" + "  " + a,
                                    new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.print("Enter 1 to add a Work Experience else 0 :");
                    n = cin.nextInt();
                    if (n == 0)
                        break;

                } while (true);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // --------------------Languages Known--------------------------------
            System.out.println("Would you like to share Languages ?\nEnter 1 if yes , else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                ch = new Paragraph("Languages", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                do {
                    System.out.print("Enter Language : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(
                            new Paragraph("        " + "\u2022" + "  " + a,
                                    new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.print("Enter 1 to add a Language else 0 :");
                    n = cin.nextInt();
                    if (n == 0)
                        break;
                } while (true);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // ------------------------Hobbies---------------------
            System.out.println("Would you like to share your Hobbies ?\nEnter 1 if yes , else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                ch = new Paragraph("Hobbies", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                do {
                    System.out.print("Enter Hobby : ");
                    a = cin.nextLine();
                    if (a.length() == 0) {
                        a = cin.nextLine();
                    }
                    resume.add(
                            new Paragraph("        " + "\u2022" + "  " + a,
                                    new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                    System.out.print("Enter 1 to add a Hobby else 0 :");
                    n = cin.nextInt();
                    if (n == 0)
                        break;
                } while (true);
                resume.add(new Paragraph("\n")); // Add some space before the line separator
                resume.add(lineSeparator);
            }
            // -------------------------Contact me------------------------------------------
            System.out.println("Would you like to share Contact Details ?\nEnter 1 if yes , else 0 : ");
            n = cin.nextInt();
            if (n == 1) {
                ch = new Paragraph("Contact Details", new Font(Font.FontFamily.TIMES_ROMAN, 15, Font.BOLD));
                ch.setAlignment(Element.ALIGN_LEFT);
                resume.add(ch);
                System.out.print("Enter mail : ");
                a = cin.nextLine();
                if (a.length() == 0) {
                    a = cin.nextLine();
                }
                do {
                    boolean valid = false;
                    Matcher matcher = EMAIL_PATTERN.matcher(a);
                    valid = matcher.matches();
                    if (valid)
                        break;
                    else
                        System.out.println("Invalid email address. Please try again.");
                } while (true);
                Chunk chunk = new Chunk("click", new Font(Font.FontFamily.TIMES_ROMAN, 10, Font.BOLD));
                Paragraph paragraph = new Paragraph();
                chunk.setAnchor("mailto:" + a);
                paragraph.add(
                        new Chunk("        " + "\u2022" + "  Mail to  ", new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                paragraph.add(chunk);
                resume.add(paragraph);
                System.out.print("Enter Linkedin profile Link : ");
                a = cin.nextLine();
                if (a.length() == 0) {
                    a = cin.nextLine();
                }
                chunk = new Chunk("click", new Font(Font.FontFamily.TIMES_ROMAN, 10, Font.BOLD));
                paragraph = new Paragraph();
                chunk.setAnchor(a);
                paragraph.add(
                        new Chunk("        " + "\u2022" + "  LinkedIn : ", new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                paragraph.add(chunk);
                resume.add(paragraph);
                System.out.print("Enter Github profile Link : ");
                a = cin.nextLine();
                if (a.length() == 0) {
                    a = cin.nextLine();
                }
                chunk = new Chunk("click", new Font(Font.FontFamily.TIMES_ROMAN, 10, Font.BOLD));
                paragraph = new Paragraph();
                chunk.setAnchor(a);
                paragraph.add(
                        new Chunk("        " + "\u2022" + "  Github : ", new Font(Font.FontFamily.TIMES_ROMAN, 10)));
                paragraph.add(chunk);
                resume.add(paragraph);
            }
            resume.close();
        } catch (

        Exception e) {
            System.out.println("Error Occured");
        }
        cin.close();
    }
}
