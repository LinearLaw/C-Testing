package com.linear.controller;

import org.springframework.stereotype.Controller;
import org.springframework.util.StringUtils;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import java.io.File;
import java.util.UUID;

/**
 * 58.5、上传文件
 *      支持：commons-fileupload
 *          commons-io
 *
 */
@Controller
@RequestMapping("/upload")
public class D02_FileUpload {

    /**
     *  58.5.1、Spring MVC 保存文件
     * @param req
     * @param uploadFile
     * @return
     * @throws Exception
     */
    @RequestMapping("/local")
    public String upload(
            HttpServletRequest req,
            MultipartFile uploadFile
    )throws Exception{

        // 1、获取文件名
        String uploadFilename = uploadFile.getOriginalFilename();

        // 2、获取文件的扩展名 - 没什么必要性
        // String extendName = uploadFilename.substring(uploadFilename.lastIndexOf(".")+1, uploadFilename.length());

        // 3、生成uuid随机数，拼接到文件名的后缀中，使得文件不重名
        String uuid = UUID.randomUUID().toString().replace("-","").toUpperCase();
        uploadFilename = uuid + "_" + uploadFilename;
        System.out.println(uploadFilename);

        // 4、设置保存路径
        String path = req.getSession().getServletContext().getRealPath("/uploads/");
        File file = new File(path);
        if(!file.exists()){
            file.mkdirs();
        }

        // 5、保存到指定文件夹
        uploadFile.transferTo(new File(path, uploadFilename));

        return "success";
    }
}
