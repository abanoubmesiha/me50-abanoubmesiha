from django.http.response import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from django.shortcuts import render
from markdown2 import Markdown

from . import util
from .forms.createEntryForm import CreateEntryForm

markdowner = Markdown()

def index(req):
    return render(req, "encyclopedia/index.html", {
        "entriesTitles": util.list_entries()
    })

def getEntry(req, title):
    entry = util.get_entry(title)
    if entry is None:
        return render(req, "encyclopedia/404.html", { "title": title })
    else:
        return render(req, "encyclopedia/view-entry.html", { "entry": markdowner.convert(entry) })

def search(req):
    q = req.POST['q']
    entry = util.get_entry(q)
    if entry is None:
        entriesTitles = util.list_entries()
        foundEntries = []
        for title in entriesTitles:
            if q.lower() in title.lower():
                foundEntries.append(title)
        if foundEntries:
            return render(req, "encyclopedia/index.html", {
                "entriesTitles": foundEntries
            })
        else:
            return render(req, "encyclopedia/404.html", { "title": q })
            
    else:
        return render(req, "encyclopedia/view-entry.html", { "entry": markdowner.convert(entry) })

def createEntry(req):
    if req.method =='POST':
        form = CreateEntryForm(req.POST)
        if form.is_valid():
            title = form.cleaned_data['title']
            content = form.cleaned_data['content']
            isExist = util.get_entry(title)
            if isExist is None:
                util.save_entry(title, content)
                return HttpResponseRedirect(reverse('view-entry', kwargs={"title": title}))
            else:
                return render(req, "encyclopedia/exist.html", { "title": title })
        else: 
            return render(req, "encyclopedia/create-entry.html", {"form": CreateEntryForm})
    else:
        return render(req, "encyclopedia/create-entry.html", {"form": CreateEntryForm})
