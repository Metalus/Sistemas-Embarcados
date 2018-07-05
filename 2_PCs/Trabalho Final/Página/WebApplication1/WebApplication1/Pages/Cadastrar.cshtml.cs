using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace WebApplication1.Pages
{
    public class CadastrarPageModel : PageModel
    {

        public string Placa { get; set; }
        public string Cor { get; set; }

        //https://www.c-sharpcorner.com/blogs/alert-message-from-controller-view-using-javascript-alert-messagebox
        public ActionResult OnPostCadastrar(string placa, string cor)
        {
            if (string.IsNullOrEmpty(placa) || string.IsNullOrEmpty(cor))
                return RedirectToPage("/Cadastrar");
            if (!Directory.Exists("/home/pi/alpr/"))
                Directory.CreateDirectory("/home/pi/alpr/");
            if (System.IO.File.Exists("/home/pi/alpr/" + placa))
                TempData["Message"] = $"Carro \\u0027{placa}\\u0027 j\\u00e1 est\\u00e1 cadastrado, use outra placa!";
            else
                using (FileStream fs = new FileStream("/home/pi/alpr/" + placa, FileMode.CreateNew, FileAccess.Write))
                {
                    byte[] bcor = Encoding.ASCII.GetBytes(cor);
                    fs.Write(bcor, 0, bcor.Length);
                    TempData["Message"] = $"Carro \\u0027{placa}\\u0027 cadastrado com sucesso!";
                }
            return RedirectToPage("/Cadastrar");

        }


        public void OnGet()
        {

        }
    }
}