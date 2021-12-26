from django.http.response import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from django.shortcuts import redirect, render
from markdown2 import Markdown
import random 

from . import util
from .forms.entryForm import EntryForm

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
        return render(req, "encyclopedia/view-entry.html", {
            "title": title,
            "entry": markdowner.convert(entry),
        })

def search(req):
    q = req.POST['q']
    entriesTitles = util.list_entries()
    entriesTitlesLower = list(map(lambda s:s.lower(), entriesTitles))

    if q.lower() in entriesTitlesLower:
        return HttpResponseRedirect(reverse('view-entry', kwargs={"title": q}))
    else:
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

def createEntry(req):
    if req.method =='POST':
        form = EntryForm(req.POST)
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
            return render(req, "encyclopedia/create-entry.html", {"form": EntryForm})
    else:
        return render(req, "encyclopedia/create-entry.html", {"form": EntryForm})

def editEntry(req, title):
    if req.method == 'POST':
        form = EntryForm(req.POST)
        if form.is_valid():
            title = form.cleaned_data['title']
            content = form.cleaned_data['content']
            util.save_entry(title, content)
            return HttpResponseRedirect(reverse('view-entry', kwargs={"title": title}))
        else: 
            return render(req, "encyclopedia/edit-entry.html", { "form": form })
    else:
        content = util.get_entry(title)

        return render(req, "encyclopedia/edit-entry.html", {
            "form": EntryForm({ 'title': title, 'content': content }),
            "title": title
        })

def randomEntry(req):
    entriesTitles = util.list_entries()
    title = random.choice(entriesTitles)
    return HttpResponseRedirect(reverse('view-entry', kwargs={"title": title}))